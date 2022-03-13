//schimba baza
//Math.log e ln
var ChangeBaseReal = (value, fromBase, toBase) => {
  let solution_str = "Nu e inca implementat";

  if (fromBase == 10) solution_str = ChangeBaseReal_FB10(value, toBase);

  //fromBase^c = toBase
  let c = Math.log(toBase) / Math.log(fromBase);

  if (c == parseInt(c)) solution_str = ChangeBaseReal_FBLOG(value, fromBase, c);

  //toBase^d = fromBase
  let d = Math.round(100 / c) / 100;
  if (d == parseInt(d)) solution_str = ChangeBaseReal_FBLOGM1(value, toBase, d);

  if (fromBase == 8 && toBase == 16) {
    let foo_sol = ChangeBaseReal_FBLOGM1(value, 2, 3);
    solution_str = ChangeBaseReal_FBLOG(foo_sol.split(" ").join(""), 2, 4);
  }
  if (fromBase == 16 && toBase == 8) {
    let foo_sol = ChangeBaseReal_FBLOGM1(value, 2, 4);
    solution_str = ChangeBaseReal_FBLOG(foo_sol.split(" ").join(""), 2, 3);
  }

  if (toBase == 10) {
    solution_str = changeBaseReal_TB10(value, fromBase);
  }

  return solution_str;
};

var changeBaseFractionary = (value, fromBase, toBase) => {
  let solution_str = "";
  if (fromBase == 10) solution_str = changeBaseFractionary_FB10(value, toBase);

  //fromBase^c = toBase
  let c = Math.log(toBase) / Math.log(fromBase);
  if (c == parseInt(c)) {
    solution_str = changeBaseFractionary_FBLOG(value, fromBase, c);
  }

  //toBase^d = fromBase
  let d = Math.log(fromBase) / Math.log(toBase);
  if (d == parseInt(d))
    solution_str = changeBaseFractionary_FBLOGM1(value, toBase, d);

  if (fromBase == 8 && toBase == 16) {
    let foo_sol = changeBaseFractionary_FBLOGM1(value, 2, 3);
    solution_str = changeBaseFractionary_FBLOG(
      foo_sol.split(" ").join(""),
      2,
      4
    );
  }
  if (fromBase == 16 && toBase == 8) {
    let foo_sol = changeBaseFractionary_FBLOGM1(value, 2, 4);
    solution_str = changeBaseFractionary_FBLOG(
      foo_sol.split(" ").join(""),
      2,
      3
    );
  }
  if (toBase == 10) {
    solution_str = changeBaseFractionary_TB10(value, fromBase);
  }

  return solution_str;
};

var ChangeBaseReal_FB10 = (value, toBase) => {
  //from base 10
  let str = "";
  value = parseInt(value);
  while (value) {
    let digit = value % toBase;
    if (digit >= 10)
      digit = String.fromCharCode("A".charCodeAt(0) + digit - 10);
    str = digit + str;
    value = parseInt(value / toBase);
  }
  return str;
};

const changeBaseFractionary_FB10 = (value, toBase) => {
  //from base 10

  value = parseFloat("0." + value);
  let max_depth = 10;
  let attempts = 0;
  let solution_str = "";
  while (value && attempts < max_depth) {
    value *= toBase;

    let digit = parseInt(value);
    if (digit >= 10)
      digit = String.fromCharCode("A".charCodeAt(0) + digit - 10);
    solution_str += digit;
    value -= parseInt(value);
    attempts++;
  }

  return solution_str;
};

const ChangeBaseReal_FBLOG = (value, fromBase, c) => {
  //fromBase^c = toBase
  let solution_str = "";
  while (value) {
    pow = 1;
    let digit = 0;
    for (let i = 0; i < c; i++) {
      digit = digit + (value % 10) * pow;
      pow *= fromBase;
      value = parseInt(value / 10);
    }
    if (digit >= 10)
      digit = String.fromCharCode("A".charCodeAt(0) + digit - 10);
    solution_str = digit + solution_str;
  }
  return solution_str;
};

const changeBaseFractionary_FBLOG = (value, fromBase, c) => {
  //fromBase^c = toBase
  let solution_str = "";
  if (value == undefined) return "";
  initialValueLength = value.toString().length;
  value = parseInt(value);
  if (initialValueLength % c != 0)
    value = value * Math.pow(10, c - (initialValueLength % c));
  while (value) {
    pow = 1;
    let digit = 0;
    for (let i = 0; i < c; i++) {
      digit = digit + (value % 10) * pow;
      pow *= fromBase;
      value = parseInt(value / 10);
    }
    if (digit >= 10)
      digit = String.fromCharCode("A".charCodeAt(0) + digit - 10);
    solution_str = digit + solution_str;
  }

  return solution_str;
};

const ChangeBaseReal_FBLOGM1 = (value, toBase, d) => {
  //toBase^d = fromBase
  let solution_str = "";
  if (value == undefined) return "";
  for (let i = 0; i < value.length; i++) {
    let digit = parseInt(value[i]);
    if (value[i] >= "A")
      digit = value[i].charCodeAt(0) - "A".charCodeAt(0) + 10;
    let temp_str = "";
    for (let j = 1; j <= d; j++) {
      temp_str = (digit % toBase) + temp_str;
      digit = parseInt(digit / toBase);
    }
    solution_str = solution_str + " " + temp_str;
  }
  return solution_str;
};

const changeBaseFractionary_FBLOGM1 = (value, toBase, d) => {
  //toBase^d = fromBase
  let solution_str = "";
  if (value == undefined) return "";
  for (let i = 0; i < value.length; i++) {
    let digit = parseInt(value[i]);
    if (value[i] >= "A") digit = value[i].charCodeAt(0) - 55;
    let temp_str = "";
    for (let j = 1; j <= d; j++) {
      temp_str = (digit % toBase) + temp_str;
      digit = parseInt(digit / toBase);
    }
    solution_str = solution_str + " " + temp_str;
  }

  return solution_str;
};

const changeBaseReal_TB10 = (value, fromBase) => {
  pow = 1;
  sum = 0;
  for (let i = value.length - 1; i >= 0; i--) {
    let digit = parseInt(value[i]);
    if (value[i] >= "A") digit = value[i].charCodeAt(0) - 55;
    sum = sum + digit * pow;
    pow *= fromBase;
  }
  return sum;
};

const changeBaseFractionary_TB10 = (value, fromBase) => {
  //ce este dupa . ca string
  if (value == undefined) return "";
  sum = 0;
  for (let i = value.length - 1; i >= 0; i--) {
    let digit = parseInt(value[i]);
    if (value[i] >= "A") digit = value[i].charCodeAt(0) - 55;
    sum = (sum + digit) / fromBase;
  }
  return (sum + " ").split(".")[1];
};

// Utilitary dommain
const InverseBits = (value) => {
  value = value.toString().split("");
  for (let i = 0; i < value.length; i++)
    if (value[i] != ".") value[i] = value[i] == 0 ? 1 : 0;
  value = value.join("");
  return value;
};

const MapToBitsNumber = (nr_bits, value, toLeft) => {
  if (nr_bits - value.length >= 0) {
    if (toLeft == true) {
      value = "0".repeat(nr_bits - value.length) + value;
    } else {
      value = value + "0".repeat(nr_bits - value.length);
    }
  } else value = value.slice(0, nr_bits);
  return value;
};

const transformInC2 = (binary) => {
  let i,
    result = "";
  for (i = binary.length - 1; i >= 0; i--) {
    result = binary[i] + result;
    if (binary[i] == "1") break;
  }
  result = InverseBits(binary.slice(0, i - binary.length)) + result;
  return result;
};
