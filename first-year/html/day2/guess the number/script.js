let num = Math.floor(Math.random() * 100) + 1;
let guessCount = 0;
let guess;
let maxTries = 7;

while (guessCount < maxTries) {
  guess = prompt("Entrez un nombre entre 1 et 100:");
  guessCount++;
  if (guess == num) {
    alert(
      "Félicitations! Vous avez deviné le nombre en " + guessCount + " essais."
    );
    break;
  } else if (guess < num) {
    alert("Trop petit! Essayez encore.");
  } else {
    alert("Trop grand! Essayez encore.");
  }
}

if (guess != num) {
  alert("Désolé, vous n'avez pas deviné le nombre. Le nombre était " + num);
}
