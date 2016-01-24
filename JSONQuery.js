function findPath(path, toFind, unexplored) {
    if (unexplored instanceof JSONArray) {
        unexploredJsonArray = (JSONArray)unexplored;
        for (var i =0; i < unexploredJsonArray.length; i++) {
                path = path+"["+i+"]";
                findPath(path, toFind, unexploredJsonArray[i]);

        }
    }
    else if (unexplored instanceof JSONObject) {
        // It's an object
        unexploredObject = (JSONObject)unexplored;
        for (var key in unexploredObject) {
            if (unexploredObject.hasOwnProperty(key)) {
                path = path+"/"+key;
                findPath(path, toFind, unexploredObject[key]);
            }
        }
    }
    else {
        if(unexplored == toFind){
            document.getElementById("demo").innerHTML = path;
        }
    }
}