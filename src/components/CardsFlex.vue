<template>
    <!-- <div class="container">
        <div class="row">
            <div class="col-md-12">
                <div class="gallery">
                    <div class="cardTop">
                        <img src="../assets/icos/celsius.png" height="50" class="" alt="Icono Humedad Tierra" />
                    </div>
                    <div class="cardTop">
                        <img src="../assets/icos/dom.png" height="50" class="" alt="Icono Sol" />
                    </div>
                    <div class="cardTop">
                        <img src="../assets/icos/humedad.png" height="50" class="" alt="Icono Humedad" />
                    </div>
                    <div class="cardTop">
                        <img src="../assets/icos/humedadTierra.png" height="50" class="" alt="Icono Humedad Tierra" />
                    </div> -->
                    <!-- <div class="card">
                        Card 5
                    </div>
                    <div class="card">
                        Card 6
                    </div> -->
                <!-- </div>
            </div>
        </div>
    </div> -->
    <br/>
<!-- Abajo Gráficos -->
    <div class="container">
        <div class="row">
            <div class="col-md-12">
                <div class="gallery">
                    <div class="card">
                        <img src="../assets/icos/celsius.png" height="50" class="colorTituloTemAmb" alt="Icono Temperatura Ambiente" />
                        <canvas id="tempAmb"></canvas>
                    </div>
                    <div class="card">
                        <img src="../assets/icos/dom.png" height="50" class="colorTituloLuzAmb" alt="Icono Sol" />
                        <canvas id="luzAmb"></canvas>
                    </div>
                    <div class="card">
                        <img src="../assets/icos/humedad.png" height="50" class="colorTituloHumAmb" alt="Icono Humedad" />
                        <canvas id="humAmb"></canvas>
                    </div>
                    <div class="card">
                        <img src="../assets/icos/humedadTierra.png" height="50" class="colorTituloHumTie" alt="Icono Humedad Tierra" />
                        <canvas id="humTie"></canvas>
                    </div>
                    <!-- <div class="card">
                        Card 5
                    </div>
                    <div class="card">
                        Card 6
                    </div> -->
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import { reactive, toRefs,onMounted,ref } from 'vue'
import axios from 'axios';
import Chart from 'chart.js/auto';
export default {
    setup () {
        const state = reactive({
            count: 0,
        })

        let registros = ref([]);
  
        let ultimo = ref([]);
        let tempAmb = ref([]);
        let copyOfDynos = [];
        let luz = [];
        let humTierra = [];
        let humAmbiente = [];
        let horas = []
    

        onMounted(() => {
            fetchRegistros();
            pintaGraficaTempAmb();
            pintaGraficaLuz();
            pintaGraficaHumTer();
            pintaGraficaHumAmb();
            setInterval("location.reload()", 120000);
            document.body.style.zoom = "99%";
        })
        const fetchRegistros = () => {
            axios.get('http://clarys.ddns.net:3000/api/dades')
                .then(response => {
                    registros.value = response.data;
                    ultimo.value = registros.value.reverse();
                    for (let i = 0; i < registros.value.length; i++) {
                        horas[i] = ultimo.value[i].hora;
                        tempAmb.value = ultimo.value[i].tempAmb;
                        luz[i] = ultimo.value[i].luzAmb;
                        humTierra[i] = ultimo.value[i].humTer;
                        humAmbiente[i] = ultimo.value[i].humAmb;
                        copyOfDynos[i] = tempAmb.value;               
                    }
                    copyOfDynos = copyOfDynos.concat(tempAmb.value)
                })
                .catch(error => {
                    console.error(error);
                });

        };

        const pintaGraficaTempAmb = () => {

            const ctx = document.getElementById("tempAmb");
            new Chart(ctx, {
                type: 'line',
                data: {
                    labels: horas,
                    datasets: [{
                        display: true,
                        label: 'Temperatura Ambiente',
                        data: copyOfDynos,
                        borderColor: 'red',
                        pointStyle: 'rectRounded',
                        borderWidth: 1
                    }]
                },
                options: {
                    responsive: true,
                    maintainAspectRatio: true,
                    scales: {
                        y: {
                            beginAtZero: true
                        }
                    }
                }
            });

        }
        const pintaGraficaLuz = () => {

            const ctx = document.getElementById("luzAmb");
            new Chart(ctx, {
                type: 'line',
                data: {
                    labels: horas,
                    datasets: [{
                        label: 'Luz Ambiental',
                        data: luz,
                        borderColor: 'orange',
                        borderWidth: 1
                        
                    }],
                    
                },
                options: {
                    responsive: true,
                    maintainAspectRatio: true,
                    scales: {
                        y: {
                            beginAtZero: true
                        }
                    }
                }
            });

        }
        const pintaGraficaHumTer = () => {

            const ctx = document.getElementById("humTie");
            new Chart(ctx, {
                type: 'line',
                data: {
                    labels: horas,
                    datasets: [{
                        label: 'Humedad Tierra',
                        data: humTierra,
                        borderColor: 'green',
                        borderWidth: 1
                    }]
                },
                options: {
                    responsive: true,
                    maintainAspectRatio: true,
                    scales: {
                        y: {
                            beginAtZero: true
                        }
                    }
                }
            });

        }
        const pintaGraficaHumAmb = () => {

            const ctx = document.getElementById("humAmb");
            new Chart(ctx, {
                type: 'line',
                data: {
                    labels: horas,
                    datasets: [{
                        label: 'Humedad Ambiente',
                        data: humAmbiente,
                        borderWidth: 1
                    }]
                },
                options: {
                    responsive: true,
                    maintainAspectRatio: true,
                    scales: {
                        y: {
                            beginAtZero: true
                        }
                    }
                }
            });

        }
    
        return {
            ...toRefs(state),
        }
    }
}
</script>
<style scoped>
.gallery{
    display: flex;
    gap: 4px;
    
}
.cardTop{
    position: relative;
    left: 0px;
    width: 80px;
    height: 65px;
    border-radius: 4px;
    padding: 8px;
    background-color: white;
    transition: 0.4s ease-in-out;
    flex: 1px;
}
.cardTop:nth-child(1){
    background-color: rgb(255, 0, 0);
    align-items: center;
    
}
.cardTop:nth-child(2){
    background-color: Orange;
    align-items: center;
}
.cardTop:nth-child(3){
    background-color: rgb(7, 153, 197);
    align-items: center;
}
.cardTop:nth-child(4){
    background-color: green;
    align-items: center;
}
.cardTop:nth-child(5){
    background-color: rgb(128, 0, 117);
}
.cardTop:nth-child(6){
    background-color: rgb(247, 248, 156);
}

.cardTop:hover {
    flex:16;
    font-weight: bold;
    background-color: rgb(255, 255, 255);
    cursor: pointer;
}
.card{
    position: relative;
    left: 0px;
    width: 80px;
    height: 200px;
    border-radius: 4px;
    padding: 8px;
    background-color: white;
    transition: 0.4s ease-in-out;
    flex: 1px;
    font-size: 16px;
}
.card:nth-child(1){
    background-color: rgb(255, 0, 0);
    align-items: center;
}
.card:nth-child(2){
    background-color: Orange;
    align-items: center;
    
}
.card:nth-child(3){
    background-color: rgb(7, 153, 197);
    align-items: center;
}
.card:nth-child(4){
    background-color: green;
    align-items: center;
}
.card:nth-child(5){
    background-color: rgb(128, 0, 117);
}
.card:nth-child(6){
    background-color: rgb(247, 248, 156);
}

.card:hover {
    flex:16;
    font-weight: bold;
    background-color: rgb(255, 255, 255);
    cursor: pointer;
    height: 570px;
}

.colorTituloTemAmb{
    background-color: red;
    padding: -10px;
}
.colorTituloLuzAmb{
    background-color: orange;
    padding: -10px;
}
.colorTituloHumAmb{
    background-color: rgb(7, 153, 197);
    padding: -10px;
}
.colorTituloHumTie{
    background-color: green;
    padding: -10px;
}

</style>