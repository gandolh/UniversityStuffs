Calculeaza_vf.addEventListener("click", () => {
	let firstNumber = first_number_input.value;
	let operation_symbol = operation_select.value;
	let secondNumber = secondNumber_input.value;
	let reprezentare = reprezentare_select.value;
	let nr_bits = nr_bits_input.value;
	const result = document.getElementById("result");
	result.style.visibility = "visible";
	result.innerHTML = Calc_vf(
		firstNumber,
		operation_symbol,
		secondNumber,
		reprezentare,
		nr_bits
	);
});

const Calc_vf = (
	firstNumber,
	operation_symbol,
	secondNumber,
	reprezentare,
	nr_bits
) => {


	let result = `${firstNumber_reprezentat} ${operation_symbol} ${secondNumber_reprezentat} = `;

	switch (reprezentare) {
		case "MS":
			if (operation_symbol == "+") {

			} else {

			}
			break;
		case "C1":
			if (operation_symbol == "+") {
				result += "NOT IMPLEMENTED YET";
			} else {
				result += "NOT IMPLEMENTED YET";
			}
			break;
		case "C2":
			if (operation_symbol == "+") {
				result += "NOT IMPLEMENTED YET";
			} else {
				result += "NOT IMPLEMENTED YET";
			}
			break;
	}

	return result;
};


const semn_to_bit = (semn) => {
  if (semn == "-") return 1;
  return 0;
};

const baza10_to_ms =(nr, biti)=>{
    ms = []
    while (nr != 0){
        ms.push(nr % 2)
        nr = parseInt(nr/2)
    }
    while( ms.length < biti)
        ms.push(0)
    return ms
}

