var change = document.getElementsByClassName("op1")
//console.log(change)
var color =
['background: rgb(22,27,130);',
 'background: rgb(32,22,130);' ,
 'background: rgb(44,22,130);' ,
 'background: rgb(64,22,130);',
 'background: rgb(83,22,130);'
]
for(let i=0 ; i<change.length;i++){
    change[i].onmouseenter = function(){
       this.setAttribute('style', 'background: rgb(6, 10, 97);') 
       //console.log(i)
    }
    change[i].onmouseleave = function(e){
              this.setAttribute('style', color[i])
    }
}