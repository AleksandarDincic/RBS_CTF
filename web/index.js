function testCrow()
{ 
    let req = new XMLHttpRequest();
    req.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("crowMsg").innerText = this.responseText;
        }
    };
    req.open("GET", "http://localhost:18080/")
    req.send()
}