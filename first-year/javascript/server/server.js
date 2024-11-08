const http = require("http");
const server = http.createServer((req, res) => {
  if (req.url === "/") {
    res.write("HELLO WORLD");
    res.end();
  } else if(req.url === "/about"){
    res.write("About Page");
    res.end();
  }else {
    res.statusCode = 404;
    res.end();
  }
});
server.listen(3000);
