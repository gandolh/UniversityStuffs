String.prototype.splice = function(idx, rem, str) {
   return this.slice(0, idx) + str + this.slice(idx + Math.abs(rem));
};


const main = (number1) => {
    //if input length
    if(number1.length!=34)
   return deLaDecLaVirgulaMobila(number1)
return deLaVirgulaMobilaLaDec(number1)
};

const deLaDecLaVirgulaMobila = (number1)=>{
    result = "";
    //fa binarul in ms
    let bin=changeBase3(number1)
    //calculeaza mantisa
    let first_index_one=bin.indexOf('1')
    let point_index= bin.indexOf('.')
    let mantisa=point_index-first_index_one;
    if(mantisa>0)mantisa--;
    // console.log('before---',bin)

    if(first_index_one<point_index){
        bin =bin.slice(first_index_one,first_index_one+1)+
         bin.slice(point_index,point_index+1) +
          bin.slice(first_index_one+1,point_index)+ 
          bin.slice(point_index+1)
    }
    else{
        bin=bin.slice(first_index_one,first_index_one+1)+
        bin.slice(point_index,point_index+1) +
        bin.slice(first_index_one+1)
    }
    // console.log('after---',bin)

    mantisa=127+mantisa
    mantisa= changeBase3(mantisa)
    if(number1[0]==-1)
    result+="1"
    else result+="0"
    while(mantisa.length<8)mantisa= '0'+mantisa;
    result+=` ${mantisa}`
    // num in binar
    numFr= (bin.split(".")[1]).toString()
    while(numFr.length<23){numFr+="0"}
    result+=` ${numFr}`
    return result;
}

const changeBase5=(number1)=>{
    sum=0;
    factor = 0.5
    for(let i=0;i<number1.length;i++){
        sum+= parseFloat(number1[i])*factor
        factor= parseFloat(factor)/2

    }
    return sum;
}

const deLaVirgulaMobilaLaDec=(number1)=>{
    result="result"
    semn= (-1)** parseInt(number1[0])
    mantisa= changeBase4(number1.split(" ")[1])
    number_fr= changeBase5(number1.split(" ")[2])
    // console.log(number_fr)
    return semn*(number_fr+1)*(2**(mantisa-127));
}
 console.log(main(25.25))
 console.log(main(0.125))
 console.log(main("0 10000011 10010100000000000000000"))
 console.log(main("0 01111100 00000000000000000000000"))
 console.log(main("1 10000001 01000000000000000000000"))

