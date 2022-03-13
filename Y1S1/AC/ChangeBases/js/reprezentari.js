Calculeaza.addEventListener("click", () => {
  let Numar = Numar_input.value;
  let nr_bits = nr_bits_input.value;
  let reprezentare = reprezentare_select.value;
  result = document.getElementById("result");
  result.style.visibility = "visible";
  result.innerHTML = "Rezultat: " + rezolva(Numar, nr_bits, reprezentare);
});

const rezolva = (Numar, nr_bits, reprezentare) => {
  result = "";
  semn = "+";
  if (Numar[0] == "-") {
    semn = "-";
    Numar = Numar.slice(1);
  }

  nr_bits = parseInt(nr_bits);
  binary = changeBase2(Numar, nr_bits);
  if (semn != "-") {
    result = "0 " + binary;
    return result;
  } else {
    result = "1 ";
    if (reprezentare == "MS") {
      result += binary;
    } else if (reprezentare == "C1") {
      if(binary.slice(0,2)=='0.')
        binary=binary.slice(2)
      result += '0.'+ InverseBits(binary);
    } else if (reprezentare == "C2") {
      result = "";
      result = transformInC2(binary);
      result = "1 " + result;
    }
    return result;
  }
};

var changeBase2 = (value, nr_bits) => {
  let fromBase = 10;
  let toBase = 2;
  value = value.toString();
  let realPart_value = value.split(".")[0];
  let fractionaryPart_value = value.split(".")[1];

  let realPartTransformed = ChangeBaseReal(realPart_value, fromBase, toBase);
  let fractionaryPartTransformed = changeBaseFractionary(
    fractionaryPart_value,
    fromBase,
    toBase
  );
  if (realPartTransformed)
    realPartTransformed = MapToBitsNumber(
      nr_bits,
      realPartTransformed,
      (toLeft = true)
    );
  if (fractionaryPartTransformed) {
    fractionaryPartTransformed = MapToBitsNumber(
      nr_bits,
      fractionaryPartTransformed,
      (toLeft = false)
    );
  }
  let result;
  if (realPartTransformed) result = realPartTransformed;
  else result = 0;
  if (fractionaryPartTransformed)
    result = result + "." + fractionaryPartTransformed;

  return result;
};
