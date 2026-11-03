(function(root){
  'use strict';
  const fresh = () => ({version:1,app:'gesp-level3',records:{},lastId:null});
  const blank = () => ({attempts:0,correctCount:0,lastAnswer:null,lastCorrect:null,wrong:false,flagged:false,mastered:false,note:'',draft:'',updatedAt:0});
  function cleanRecord(raw) {
    const r=blank(); if(!raw || typeof raw!=='object') return r;
    const integer=x=>Number.isSafeInteger(x)&&x>=0?Math.min(x,1000000):0;
    r.attempts=integer(raw.attempts);r.correctCount=Math.min(integer(raw.correctCount),r.attempts);
    r.lastAnswer=['A','B','C','D','T','F'].includes(raw.lastAnswer)?raw.lastAnswer:null;
    r.lastCorrect=typeof raw.lastCorrect==='boolean'?raw.lastCorrect:null;
    for(const k of ['wrong','flagged','mastered'])r[k]=raw[k]===true;
    r.note=typeof raw.note==='string'?raw.note.slice(0,20000):'';
    r.draft=typeof raw.draft==='string'?raw.draft.slice(0,60000):'';
    r.updatedAt=Number.isFinite(raw.updatedAt)?Math.min(Math.max(raw.updatedAt,0),Date.now()+86400000):0;
    return r;
  }
  function validate(raw,ids) {
    if(!raw || raw.version!==1 || raw.app!=='gesp-level3' || !raw.records || typeof raw.records!=='object' || Array.isArray(raw.records))throw Error('這不是支援的 GESP 學習紀錄檔。');
    const s=fresh();const allowed=new Set(ids);
    for(const [id,r] of Object.entries(raw.records))if(allowed.has(id))s.records[id]=cleanRecord(r);
    if(allowed.has(raw.lastId))s.lastId=raw.lastId;
    return s;
  }
  function answerRecord(record,answer,correct,time=Date.now()) {
    const r=cleanRecord(record);r.attempts++;r.correctCount+=correct?1:0;r.lastAnswer=answer;r.lastCorrect=correct;
    if(!correct){r.wrong=true;r.mastered=false;}
    r.updatedAt=time;return r;
  }
  function merge(a,b) {
    const out=fresh();out.lastId=a.lastId||b.lastId;
    for(const id of new Set([...Object.keys(a.records),...Object.keys(b.records)])){
      const ar=a.records[id],br=b.records[id];out.records[id]=!ar?br:!br?ar:br.updatedAt>ar.updatedAt?br:ar;
    }
    return out;
  }
  const pending=r=>!!r && !r.mastered && (r.wrong||r.flagged);
  const api={fresh,blank,cleanRecord,validate,answerRecord,merge,pending};
  if(typeof module!=='undefined'&&module.exports)module.exports=api;
  root.GespStore=api;
})(typeof window==='undefined'?globalThis:window);
