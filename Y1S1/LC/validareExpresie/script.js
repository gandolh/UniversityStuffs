
for(let el of document.getElementsByClassName('symbols'))
  el.addEventListener('click',(e)=>{
    expresieInput.value+=e.target.innerText;
  })




const valid_fbf = () => {
  //preiau expresia
  let expresie = expresieInput.value;

  //elimin caracterele invizibile si spatiile.
  expresie = expresie.split(" ").join("");
  expresie = expresie.split("\n").join("");
  expresie = expresie.split("\t").join("");
  //console.log(expresie)
  let expCompuse = [];
  seAsteapta = ["(", "fbf"];
  for (let ch of expresie) {
    i = expresie.indexOf(ch);
    let ch_placeholder = ch;

    if (ch_placeholder >= "A" && ch_placeholder <= "Z") ch_placeholder = "fbf";

    if (seAsteapta.indexOf(ch_placeholder) == -1) return 0;
    switch (ch) {
      case "(":
        expCompuse.push(0);  //status
        seAsteapta = ["fbf", "¬", "("];
        break;
      case "¬":
        expCompuse[expCompuse.length-1]=1;
        seAsteapta = ["fbf", "("];
        break;
      case "∧":
        seAsteapta = ["fbf", "("];
        expCompuse[expCompuse.length-1]=1;
        break;
      case "⇔":
        seAsteapta = ["fbf", "("];
        expCompuse[expCompuse.length-1]=1;
        break;
      case "∨":
        seAsteapta = ["fbf", "("];
        expCompuse[expCompuse.length-1]=1;
        break;
      case "⇒":
        seAsteapta = ["fbf", "("];
        expCompuse[expCompuse.length-1]=1;
        break;
      case ")":
        if(expCompuse[expCompuse.length-1]==0)return 0;
        if(expCompuse.length==0)return 0;
        expCompuse.pop(); //se termina expresie compusa
        seAsteapta = ["∧", "⇔", "∨", "⇒",")"];
        break;
      default:
        if (ch >= "A" && ch <= "Z") {
          //inseamna ca e o fbf pentru ca A-Z sunt propozitii atomice.
          seAsteapta = ["∧", "⇔", "∨", "⇒", ")"];
        } else return 0;
    }
  }
  if (expCompuse.length  != 0) return 0;
  return 1;
};

Verifica.addEventListener("click", () => {
  if(valid_fbf()==1){
      response_message.innerHTML="Formula bine formata."
      response_message.style.color="#6ECB63"
    }
    else{
        response_message.innerHTML="Formula incorect formata."
        response_message.style.color="#FF0075"
    }
    response_message.style.visibility="visible"
});

