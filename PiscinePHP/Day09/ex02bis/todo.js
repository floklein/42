// Cookies
function getCookies() {
    // Get Cookies
    var split = document.cookie.split(';');

    // Clean
    var data = [];
    split.forEach(function (cookie) {
        data.push(cookie.trim());
    });
    delete split;

    // Split each cookie to get id
    var ret = [];
    for (var cookie in data) {
        if (!data[cookie])
            continue;
        split = data[cookie].split('=');
        ret[parseInt(split[0])] = split[1];
    }
    return (ret);
}

function addCookie(id, name) {
    document.cookie = id + "=" + name;
}

function delCookie(id) {
    var date = new Date(0);
    document.cookie = id + "=;expires=" + date.toUTCString();
}

// Todo
var size = 0;
var list = $("#ft_list");

var cookies = getCookies();
for (let id in cookies) {
    newTodo(id, cookies[id]);
    size++;
}

function newTodo(id, name) {
    var div = document.createElement("div");
    div.classList.add("ft_todo");
    div.id = id;
    div.innerText = name;
    div.onclick = function () { delTodo(id); };
    list.prepend(div);
}
function addTodo() {
    var ret = prompt("Veuillez entrer votre nouveau todo");

    if (!ret)
        return;

    newTodo(size, ret);
    addCookie(size, ret);
    size++;
}
function delTodo(id) {
    var todo = $("#" + id);

    if (confirm("Voulez-vous vraiment supprimer " + todo.innerText + " ?")) {
        delCookie(id);
        todo.remove();
        size--;
    }
}