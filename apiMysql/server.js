const express = require('express');
const mysql = require('mysql');

// Configura la conexión a la base de datos MySQL
const db = mysql.createConnection({
  host: 'clarys.ddns.net',
  user: 'ablancaa',
  password: 'Bla19Cal',
  database: 'sensitivepot'
});

// Conéctate a la base de datos
db.connect(err => {
  if (err) {
    throw err;
  }
  console.log('Conexión a la base de datos establecida');
});

// Crea una instancia de Express
const app = express();

// Middleware para permitir solicitudes desde cualquier dominio
app.use((req, res, next) => {
  res.setHeader('Access-Control-Allow-Origin', '*');
  res.setHeader('Access-Control-Allow-Methods', 'GET, POST, PUT, DELETE');
  res.setHeader('Access-Control-Allow-Headers', 'Content-Type');
  next();
});

// Obtén todos los registros de la base de datos
app.get('/api/dades', (req, res) => {
  const sql = 'SELECT * FROM dades';

  db.query(sql, (err, result) => {
    if (err) {
      throw err;
    }
    res.json(result);
  });
});
// Obtén todos los registros de la base de datos
app.get('/api/estado', (req, res) => {
  const sql = 'SELECT * FROM estado';

  db.query(sql, (err, result) => {
    if (err) {
      throw err;
    }
    res.json(result);
  });
});

// Agrega un nuevo registro a la base de datos
app.post('/api/dades', (req, res) => {
  const { campo1, campo2, campo3 } = req.body;
  const sql = 'INSERT INTO dades (campo1, campo2, campo3) VALUES (?, ?, ?)';
  const values = [campo1, campo2, campo3];

  db.query(sql, values, (err, result) => {
    if (err) {
      throw err;
    }
    res.json(result);
  });
});

// Inicia el servidor
const port = 3000;
app.listen(port, () => {
  console.log(`Servidor en ejecución en http://localhost:${port}`);
});
