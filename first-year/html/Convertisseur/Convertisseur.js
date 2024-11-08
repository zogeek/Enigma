const unitsInMeters = {
  meter: 1,
  kilometer: 1000,
  centimeter: 0.01,
  millimeter: 0.001,
  micrometer: 0.000001,
  nanometer: 0.000000001,
  inch: 0.0254,
  foot: 0.3048,
  yard: 0.9144,
  mile: 1609.34,
  litter: 1,
  centilitter: 0.01,
  milliliter: 0.001,
  gallon: 0.264172,
  pint: 2.11338,
  quart: 0.946353,
  "homme": 1.756,
  smartphone: 0.1467,
  "ariane 5": 56,
  "golden gate": 1970,
  "football field": 91.44,
  "blue whale": 25,
  "eiffel tower": 330,
  "empire state building": 443.2,
};

function convert(unitFrom, unitTo, value) {
  const valueInMeters = value * unitsInMeters[unitFrom.toLowerCase()];
  const convertedValue = valueInMeters / unitsInMeters[unitTo.toLowerCase()];
  return convertedValue;
}

function executeConversion() {
  const value = document.getElementById("value").value;
  const unitFrom = document.getElementById("unitFrom").value;
  const unitTo = document.getElementById("unitTo").value;
  let result = convert(unitFrom, unitTo, value);
  result = result.toFixed(2);
  const resultElement = document.getElementById("result");
  resultElement.innerText = `${value} ${unitFrom} in ${unitTo} do ${result} ${unitTo}`;
}

function exchange() {
  const unitFrom = document.getElementById("unitFrom").value;
  const unitTo = document.getElementById("unitTo").value;
  document.getElementById("unitFrom").value = unitTo;
  document.getElementById("unitTo").value = unitFrom;
}
