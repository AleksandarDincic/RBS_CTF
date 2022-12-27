function testCrow()
{ 
    let req = new XMLHttpRequest();
    req.onreadystatechange = function () {
        if (this.readyState == 4) {
            if(this.status == 200)
            {
                document.getElementById("errorText").innerText = this.responseText;
                window.location.assign("flag.html");
            }
            else
                document.getElementById("errorText").innerText = "Error";
        }
    };
    req.open("POST", "http://localhost:18080/ctf2",)
    req.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
    req.send(JSON.stringify({ "username": document.getElementById("address").value}));
}