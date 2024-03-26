const express = require('express')
const res = require('express/lib/response')

const app = express()

app.get('/', (req, res) => {
    res.send('<h1>Hello! Welcome.</h1>')
})

app.listen(3000)