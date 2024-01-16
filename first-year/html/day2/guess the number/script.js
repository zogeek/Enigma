let randomNumber = Math.floor(Math.random() * 100);
let guessCount = 0;
let maxTries = 7;
console.log(randomNumber);

const numberToGuess = randomNumber;
const $guessSection = document.querySelector("ul");

const displayGuess = (where, text, userGuess) => {
  const $li = document.createElement("li");
  $guess.textContent = ${text} + ${userGuess};
  where.appendChild($guess);
}

document

function guessTheNumber() {
  let guess = document.getElementById("guessNumber").value;
  console.log(guess);
  console.log(randomNumber);
  if (guess < 0) {
    const p = document.createElement("p");
    p.textContent = "Veuillez saisir un nombre positif";
    document.body.appendChild(p);
  } else if (guess > 100) {
    const p = document.createElement("p");
    p.textContent = "Veuillez saisir un nombre positif";
    document.body.appendChild(p);
  } else if (guessCount < maxTries) {
    guessCount++;
    let leftTries = maxTries - guessCount;
    if (guess == randomNumber) {
      const p = document.createElement("p");
      p.textContent =
        "Felicitations vous avez gagner en " +
        guessCount +
        " essais le nombre etait bien " +
        randomNumber;
      document.body.appendChild(p);
    } else if (guess < randomNumber) {
      const p = document.createElement("p");
      p.textContent =
        "Le nombre " +
        guess +
        " est trop petit , il vous reste " +
        leftTries +
        " essais";
      document.body.appendChild(p);
    } else if (guess > randomNumber) {
      const p = document.createElement("p");
      p.textContent =
        "Le nombre " +
        guess +
        " est trop grand, il vous reste " +
        leftTries +
        " essais";
      document.body.appendChild(p);
    }
  } else {
    const p = document.createElement("p");
    p.textContent = "Vous n'avez plus d'essais";

    document.body.appendChild(p);
  }
}
