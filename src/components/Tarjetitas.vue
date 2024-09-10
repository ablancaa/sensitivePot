<template>
   
        <h1>Tarjetitas</h1>
        <div class="container">
  <div class="content">
    <p class="texto">Temperatura: 29,3</p>
    <p class="texto">Luz: 20</p>
    <p class="texto">Humedad Ambiente: 25</p>
    <p class="texto">Humedad Tierra: 6</p>
  </div>
  <div class="flap"></div>
</div>
        

</template>

<script setup>

</script>
<script>
export default {
    name: 'Trajetitas_info',
}
</script>
<style  scoped>
@import url('https://fonts.googleapis.com/css2?family=Merriweather:wght@300;900&display=swap');

body {
  background: #f2f2f2;
  
}

.container  {
  position: absolute;
  left: 50%;
  top: 50%;
  transform: translate(-50%, -50%);
  height: 100px;
  width: 200px;
  background: #f2f2f2;
  overflow: hidden;
  border-radius: 20px;
  cursor: pointer;
  box-shadow: 0 0 20px 8px #d0d0d0;
 
  
}

.content {
  position: absolute;
  top: 50%;
  transform: translatey(-50%);
  text-align: justify;
  color: black;
  padding: 40px;
  font-family: 'Merriweather', serif;
  
}

h1 {
  font-weight: 900;
  text-align: center;
}

h3 {
  font-weight: 300;
}

.flap {
  width: 100%;
  height: 100%;
}

.flap::before {
  position: absolute;
  content: "";
  height: 100%;
  width: 50%;
  background: url("https://pbs.twimg.com/profile_images/1347260174176710658/2GfSZ1i__400x400.jpg") white;
  background-position: 100px;
  background-repeat: no-repeat;
  transition: 1s;
   background-image: url(https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRdJzZ5hnhiAKARqQerdw7TXVS2ocgrQH2fYQ&s)
}

.flap::after {
  position: absolute;
  content: "";
  height: 100%;
  width: 50%;
  right: 0;
  background: url("https://pbs.twimg.com/profile_images/1347260174176710658/2GfSZ1i__400x400.jpg") white;
  background-position: -200px;
  background-repeat: no-repeat;
  transition: 1s;
   background-image: url(https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRdJzZ5hnhiAKARqQerdw7TXVS2ocgrQH2fYQ&s)
}

.container:hover .flap::after {
  transform: translatex(300px);
  
}

.container:hover .flap::before{
  transform: translatex(-300px);
  
}
</style>