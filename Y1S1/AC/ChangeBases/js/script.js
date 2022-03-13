Calculeaza.addEventListener('click',()=>{
    result.style.visibility="visible"
    result.innerHTML = changeBase();
})

var changeBase = ()=>{

    let fromBase= parseInt(fromBase_input.value)
    let toBase= parseInt(toBase_input.value);
    let value = nrTransform_input.value;
    let realPart_value= value.split(".")[0];
    let fractionaryPart_value = value.split(".")[1];
    
    //daca avem o eroare o afisam si nu mai executam nimic.
    let ok = ValidCheck(value,fromBase,toBase);
    if(!ok.succesfully)
        return ok.errorCode;
    

    //calculeaza schimbarea partii intregi a numarului.
    let realPartTransformed = ChangeBaseReal(realPart_value,fromBase,toBase);
    //calculeaza schimbarea partii fractionare a numarului
    let fractionaryPartTransformed = changeBaseFractionary(fractionaryPart_value,fromBase,toBase);
    let result;

    // daca am parte reala transformata adaug-o la rezultat
    //altfel consider-o 0.
    if(realPartTransformed)
        result = realPartTransformed;
    else result =0;

    //daca exista parte fractionara adaug-o la rezultat
    if(fractionaryPartTransformed)
        result= result + '.' + fractionaryPartTransformed;
    

    //returneaza rezultatul.
    return result;
}


