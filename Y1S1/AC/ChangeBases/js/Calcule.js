
if(typeof Calculeaza !== 'undefined')
Calculeaza.addEventListener('click',()=>{
    let bazaDeCalcul=BazaDeCalcul_input.value;
    let first_number=first_number_input.value;
    let operation_symbol=operation_select.value;
    let secondNumber=secondNumber_input.value;
    result= document.getElementById('result');
    result.style.visibility="visible"
    result.innerHTML = 'Rezultat: '+ Calc(bazaDeCalcul,first_number,operation_symbol,secondNumber);
})

const Calc=(bazaDeCalcul,first_number,operation_symbol,secondNumber)=>{
    result='';
    bazaDeCalcul=parseInt(bazaDeCalcul)
    switch(operation_symbol){
        case '+':
           result= Aduna(bazaDeCalcul,first_number,secondNumber);
            break;
        case '-':
           result= Scade(bazaDeCalcul,first_number,secondNumber);
            break;
        case '*':
           result= Inmulteste(bazaDeCalcul,first_number,secondNumber);
            break;
        case '/':
           result= Imparte(bazaDeCalcul,first_number,secondNumber);
            break;
        default:
            result='Nu e inca implementat'
    }
    return result;
}

const Aduna=(bazaDeCalcul,first_number,secondNumber)=>{
    result='';

    //se adauga 0 in fata pana ajung la aceeasi lungime.
    let max_length= Math.max(first_number.length,secondNumber.length)
    first_number= addToLength(first_number,max_length);
    secondNumber= addToLength(secondNumber,max_length);
    let transport=0;
    //parcurg cifra cu cifra de la final
    for(let i=max_length-1;i>=0;i--){
        f_num = transformCharintoInteger(first_number[i]);
        s_num= transformCharintoInteger(secondNumber[i]);
        let digit= f_num+s_num;

        if(transport==1){
            transport=0;
            digit++;
        }
        if(digit>=bazaDeCalcul){
            transport=1;
            digit=digit- bazaDeCalcul;
        }
        if(digit>=10)digit= String.fromCharCode("A".charCodeAt(0) + digit-10);
        result= digit +  result;
    }
    if(transport==1)
        result='1'+result;
    return result;
}
const Scade=(bazaDeCalcul,first_number,secondNumber)=>{

    result='';
    //se adauga 0 in fata pana ajung la aceeasi lungime.
    let max_length= Math.max(first_number.length,secondNumber.length)
    first_number= addToLength(first_number,max_length);
    secondNumber= addToLength(secondNumber,max_length);
    let imprumut=0;
    //parcurg cifra cu cifra de la final
    for(let i=max_length-1;i>=0;i--){
        f_num = transformCharintoInteger(first_number[i]);
        s_num= transformCharintoInteger(secondNumber[i]);
        let digit= f_num-s_num;

        if(imprumut==1){
            imprumut=0;
            digit--;
        }
        if(digit<0){
            imprumut=1;
            digit=bazaDeCalcul + digit;
        }
        if(digit>=10)digit= String.fromCharCode("A".charCodeAt(0) + digit-10);
        result= digit +  result;
    }
    if(imprumut==1)
        result='-'+result;
    return result;

}
const Inmulteste=(bazaDeCalcul,first_number,secondNumber)=>{
    result='';
    //se adauga 0 in fata pana ajung la aceeasi lungime.
    let sum_prod='0';
    let zero_str='';
    for(let i=secondNumber.length-1;i>=0;i--){
        s_num=transformCharintoInteger(secondNumber[i])
        temp_prod='';
        transport=0;
        for(let i=first_number.length-1;i>=0;i--){
            f_num=transformCharintoInteger(first_number[i])
            let digit= f_num* s_num;
            if(transport){
                digit+=transport;
                transport=0;
            }
            if(digit>=bazaDeCalcul){
                transport= parseInt(digit/bazaDeCalcul);
                digit= digit%bazaDeCalcul;
            }

            if(digit>=10)digit= String.fromCharCode("A".charCodeAt(0) + digit-10);
            temp_prod= digit +  temp_prod;
        }
        temp_prod+=zero_str;
        zero_str=zero_str+'0';
        sum_prod= Aduna(bazaDeCalcul,sum_prod,temp_prod);
    }
    if(transport)sum_prod=transport+sum_prod;
    return sum_prod;
}

const Imparte=(bazaDeCalcul,first_number,secondNumber)=>{
    initialLength_sn= secondNumber.length;

    while(secondNumber.length<first_number.length)
        secondNumber+='0';
    Rezultat='';


   while(secondNumber.length>=initialLength_sn){


    rest=first_number;
    cat_num=0;
    do{
        first_number=rest;
        cat_num++;
        rest= Scade(bazaDeCalcul,rest,secondNumber)
        console.log(rest,first_number)
    }while(rest[0]!='-');
    cat_num--;
    Rezultat=Rezultat+''+cat_num;
    secondNumber=secondNumber.slice(0,-1);
    
   }
   return parseInt(Rezultat)+ ' rest ' + parseInt(first_number);
}



const transformCharintoInteger = (f_num)=>{
    if(f_num>='A' && f_num<='Z')
    f_num=f_num.charCodeAt(0)- 55;  
else f_num=parseInt(f_num)
    return f_num;
}

const addToLength=(arr,length)=>{
    while(arr.length<length)arr = '0'+arr;
    return arr;
}