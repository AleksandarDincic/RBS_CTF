var fuckingHeader = "<tr><th>Ime</th><th>Pare</th></tr>";

function refreshTable(data) { 
    let table = document.getElementById("table");
    table.innerHTML = fuckingHeader;
    for (let row in data) { 
        let tr = document.createElement('tr');

        let td = document.createElement('td');
        td.innerHTML = row;
        tr.appendChild(td);
        
        td = document.createElement('td');
        td.innerHTML = data[row];
        tr.appendChild(td);

        table.appendChild(tr);
    }
}


function testCrow()
{ 
    let req = new XMLHttpRequest();
    req.onreadystatechange = function () {
        if (this.readyState == 4) {
            if(this.status == 200)
            {
                let data = JSON.parse(this.responseText);
                refreshTable(data);
            }
            else
                document.getElementById("flagStatus").innerText = "Error";
        }
    };
    req.open("GET", "http://localhost:18080/ctf3/getData");
    req.send();
}

function changeMoney() { 
    let req = new XMLHttpRequest();
    req.onreadystatechange = function () {
        if (this.readyState == 4) {
            if(this.status == 200)
            {
                let data = JSON.parse(this.responseText);
                refreshTable(data);
            }
            else
                document.getElementById("flagStatus").innerText = "Error";
        }
    };
    req.open("POST", "http://localhost:18080/ctf3/changeMoney");
    req.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
    req.send(JSON.stringify({ "name": document.getElementById("nameField").value, "newAmount" : document.getElementById("moneyField").value}))
}

function getFlag() { 
    let req = new XMLHttpRequest();
    req.onreadystatechange = function () {
        if (this.readyState == 4) {
            if(this.status == 200)
            {
                document.getElementById("flagStatus").innerText = this.responseText;
            }
            else
                document.getElementById("flagStatus").innerText = "Error";
        }
    };
    req.open("GET", "http://localhost:18080/ctf3/getFlag");
    req.send();
}