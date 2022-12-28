function createList() { 
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
    req.open("POST", "http://localhost:18080/ctf9/createList");
    req.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
    req.send(JSON.stringify({ "size": document.getElementById("sizeField").value, "values" : document.getElementById("valuesField").value}))
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
    req.open("GET", "http://localhost:18080/ctf9/getFlag");
    req.send();
}