function testCrow()
{ 
    let req = new XMLHttpRequest();
    req.onreadystatechange = function () {
        if (this.readyState == 4) {
            if(this.status == 200)
            {
                let json = JSON.parse(this.responseText);
                document.getElementById("Flag").innerText = json["flag"];
            }
            else
                document.getElementById("errorText").innerText = "Error";
        }
    };
    req.open("POST", "http://localhost:18080/ctf5",)
    req.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
    req.send(JSON.stringify({ "numItems": document.getElementById("numItems").value}));
}