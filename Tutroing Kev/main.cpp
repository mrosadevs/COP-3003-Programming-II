                            var t
if (typeof DB !== "undefined" && DB.createTask) {
    t = DB.createTask("New to-do list", "", "", 1)
}
if (t && t.id !== undefined) {
    taskModel.append(t)
} else {
    taskModel.append({
        "id": -1,
        "title": "New to-do list",
        "description": "",
        "dueDate": "",
        "cardType": 1
    })
}