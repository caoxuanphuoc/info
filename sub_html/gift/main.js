var no= document.querySelectorAll('.ans div')[1]
no.onmousemove= function(e){
    var x= Math.round(Math.random()* 1000)%300, y= Math.round(Math.random()* 1000)%200;
    no.setAttribute ('style', `transform: translateX(${x}px) translateY(${y}px);`)
}
var yes = document.querySelector('.ans div')
yes.onclick = function(e){
  var conga =document.querySelector('.congat')
  conga.setAttribute('style', `display: flex;`)
    setTimeout(() =>{
        conga.setAttribute('style', `display: none;`)
    },1000)
}