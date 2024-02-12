import express from "express";
const app = express();
app.use(express.json());

import { createClient } from "@supabase/supabase-js";
const supabaseUrl = "https://ecbvscmrpqrqrpczhvnb.supabase.co";
const supabaseKey =
  "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImVjYnZzY21ycHFycXJwY3podm5iIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MDczODM5NzgsImV4cCI6MjAyMjk1OTk3OH0._0nfsLhsl6BUMmWKBKjcJ_xD-ZTi8Lpb3_68u1UmJJg";
const supabase = createClient(supabaseUrl, supabaseKey);

app.get("/products", async (req, res) => {
  const { data, error } = await supabase.from("table1").select();
  if (error) {
    return res.status(400).json({ error: error.message });
  }
  res.send(data);
});
app.listen(3000, () => console.log(`Listening on port 3000 ...`));
