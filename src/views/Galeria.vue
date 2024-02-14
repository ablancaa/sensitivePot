<template>
<div class="container">
    <h1>Galería de Fotos</h1>
        <div class="row">
                
                <div class="col-md-4">
                    <img src="../assets/fotos/photo_2023-05-31_17-07-04.jpg" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/photo_2023-05-31_17-07-07.jpg" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/photo_2023-05-31_17-07-10.jpg" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/pot1.png" height="" class="polaroid" />
                </div>
                
                <div class="col-md-4">
                    <img src="../assets/fotos/pot2.png" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/Pot3.png" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/Pot4.png" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/Pot5.png" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/Pot6.png" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/photo_2023-06-01_18-04-45.jpg" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/photo_2023-06-01_18-04-47.jpg" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/fotos/photo_2023-06-01_18-04-52.jpg" height="" class="polaroid" />
                </div>
                <div class="col-md-4">
                    <img src="../assets/sensores/todosloscomponentes.jpg" height="" class="polaroid" />
                </div>
                
            </div>
        </div>
        <br/><br/>
</template>

<script setup>

</script>
<script>
export default {
    name: 'Sensores-1',
    setup(){

        return {}
    }
}
</script>

<style scoped>
.container {
    margin-top: 60px;
}
.polaroid {
  height: 270px;
  background-color: white;
  padding: 10px 10px 50px 10px;
  border: 1px solid #bfbfbf;
  box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
  margin-top: 30px;
}
</style>