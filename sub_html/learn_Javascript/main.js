Array.prototype.every2= function(callBack){
    for( var x in this){
        if(this.hasOwnProperty(x)){
            if(! callBack(this[x], x, this)){
                return false
            }
                
        }
    }
    return true
}
var a=[
    1, 2, 3, 4, 5
]
var k= a.every2(function(value, index, array){
    return value < 3
})
console.log(k)