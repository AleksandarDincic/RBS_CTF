function testCrow2()
{
    let req = new XMLHttpRequest();
    req.onreadystatechange = function () {
        if (this.readyState == 4) {
            if(this.status == 200)
            {
                let json = JSON.parse(this.responseText)
                document.getElementById("name").innerText = json["name"];
                document.getElementById("price").innerText = json["price"];
                document.getElementById("year").innerText = json["year"];
                document.getElementById("brand").innerText = json["brand"];
                document.getElementById("comment").innerText = json["comment"];
                document.getElementById("sold").innerText = json["sold"];
            }
            else
                document.getElementById("errorText").innerText = "Error";
        }
    };
    req.open("GET", "http://localhost:18080/ctf4",)
    req.send();
}

function testCrow()
{ 
    let req = new XMLHttpRequest();
    req.onreadystatechange = function () {
        if (this.readyState == 4) {
            if(this.status == 200)
            {
                document.getElementById("errorText").innerText = this.responseText;
                testCrow2();
            }
            else
                document.getElementById("errorText").innerText = "Error";
        }
    };
    req.open("POST", "http://localhost:18080/ctf4",)
    req.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
    req.send(JSON.stringify({ "comment": document.getElementById("newComment").value}));
}