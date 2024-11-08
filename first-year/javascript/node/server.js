const os = require("os");

setInterval(() => {
      console.clear();
  console.log(
    "Used memory: " +
      ((os.totalmem() - os.freemem()) / 1024 / 1024 / 1024).toLocaleString(
        undefined,
        {
          maximumFractionDigits: 2,
          minimumFractionDigits: 2,
        }
      ) +
      "/" +
      (os.totalmem() / 1024 / 1024 / 1024).toLocaleString(undefined, {
        maximumFractionDigits: 2,
        minimumFractionDigits: 2,
      }) +
      " Go"
  );


}, 1000);
