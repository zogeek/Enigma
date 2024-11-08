const express = require("express");
const app = express();

app.use(express.json());

app.get("/", (req, res) => {
  res.send("HELLO WORLD");
});

app.get("/about", (req, res) => {
  res.send("About Page");
});

app.get("/easter-egg", (req, res) => {
  res.redirect("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
});

app.get("/contact", (req, res) => {
  res.send("HELLO WORLD");
});
const port = process.env.PORT || 3000;
app.listen(port, () => console.log(`Listening on port ${port}...`));
