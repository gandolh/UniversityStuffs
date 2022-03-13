

const changeBase3 = (number1)=>{
    return Number(number1).toString(2);
}

const changeBase4 = (number1)=>{
    return parseInt((number1).replace(/[^01]/gi, ''), 2);
}