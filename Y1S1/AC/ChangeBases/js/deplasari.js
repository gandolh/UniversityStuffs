Calculeaza.addEventListener("click", () => {
  let Numar = Numar_input.value;
  let nr_bits = nr_bits_input.value;
  let sens_deplasare = sens_deplasare_input.value;
  let reprezentare = reprezentare_select.value;
  result = document.getElementById("result");
  result.style.visibility = "visible";
  result.innerHTML =
    "Rezultat: " + rezolva(Numar, nr_bits, sens_deplasare, reprezentare);
});

const rezolva = (Numar, nr_bits, sens_deplasare, reprezentare) => {
  let result = "";
  let semn = "+";
  if (Numar[0] == "-") {
    semn = "-";
    Numar = Numar.slice(1);
  }
  nr_bits = parseInt(nr_bits);
  binary = changeBase2(Numar, nr_bits);
  realPart = binary.split(".")[0];
  fractionaryPart = binary.split(".")[1];
  if (semn != "-")
  result = "0 ";
  else
  result = "1 ";
  
  
  let realPart_After =0;
  if(realPart!=0)
    realPart_After = deplasare(
      realPart,
      semn,
      sens_deplasare,
      reprezentare
      );
    let fractionaryPart_After = deplasare(
      fractionaryPart.split("").reverse().join(""),
      semn,
      -sens_deplasare,
      reprezentare
      )
      .split("")
      .reverse()
      .join("");
      if (realPart_After) result += realPart_After;
      else result += "0";

  if (fractionaryPart_After)
    result +="." + fractionaryPart_After;
  return result;
};

const deplasare = (binary, semn, sens_deplasare, reprezentare) => {
  let result = "";
  if (semn != "-") {
    //adica e pozitiv
    result += move_bits(binary, sens_deplasare, 0);
  } else {
    switch (reprezentare) {
      case "MS":
        result += move_bits(binary, sens_deplasare, 0);
        break;
      case "C1":
        binary = InverseBits(binary);
        result += move_bits(binary, sens_deplasare, 1);
        break;
      case "C2":
        binary = transformInC2(binary);
        if (sens_deplasare[0] == "-")
          result += move_bits(binary, sens_deplasare, 1);
        else result += move_bits(binary, sens_deplasare, 0);
        break;
    }
  }
  return result;
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
  if (realPartTransformed) {
    realPartTransformed = MapToBitsNumber(
      nr_bits,
      realPartTransformed,
      (toLeft = true)
    );
  }
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

const move_bits = (binary, sens_deplasare, filling_digit) => {
  sens_deplasare = parseInt(sens_deplasare);
  binary_arr = binary.split("");
  let n = binary_arr.length - 1;
  if (sens_deplasare >= 0) {
    for (let i = 0; i <= n; i++) binary_arr[i] = binary_arr[i + sens_deplasare];
    binary_arr.fill(filling_digit, n - sens_deplasare + 1, n + 1);
  } else {
    for (let i = n; i >= 0; i--) binary_arr.swap(i,i+sens_deplasare)
    binary_arr.fill(filling_digit, 0, -sens_deplasare);
    //este de forma binary_arr[-1],[-2],etc.
    // for construire si ducere in functia de sus
  }
  return binary_arr.join("");
};

Array.prototype.swap = function (x, y) {
  var b = this[x];
  this[x] = this[y];
  this[y] = b;
  return this;
};
