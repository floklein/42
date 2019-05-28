const express = require('express');

const app = express();

app.get('/api/customers', (req, res) => {
    const customers = [
        {id: 1, firstName: 'Florent', lastName: 'Klein'},
        {id: 2, firstName: 'Juliette', lastName: 'Benedetti'},
        {id: 3, firstName: 'Pierre-Antoine', lastName: 'Jujard'}
    ];

    res.json(customers);
});

const port = 5000;

app.listen(port, () => {
    console.log(`Server started on port ${port}`)
});