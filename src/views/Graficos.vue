<template>
    <div class="container">
        <h1>Gráficos</h1>
        <div class="row">
            <div class="col-md-12" v-if="este == 1">
                <img :src="cara1" height="" class="polaroid" />
            </div>
        <div class="row">
            <div class="col-md-12 " v-if="este == 2">
                <img :src="cara2" height="" class="polaroid" />
            </div>
        </div>
            <div class="col-md-12" v-if="este == 3">
                <img :src="cara3" height="" class="polaroid" />
            </div>
            <div class="col-md-12" v-if="este == 4">
                <img :src="cara4" height="" class="polaroid" />
            </div>
            <div class="col-md-12" v-if="este == 5">
                <img :src="cara5" height="" class="polaroid" />
            </div>
            </div>
    </div><!-- fin -->
            
<div class="row">


</div>
<br/><br/>
<div class="row">
    <div class="col-md-6">
        <button class="accordion"><img src="../assets/icos/celsius.png" height="50" class="colorTituloTemAmb marginRight" alt="Icono Temperatura Ambiente" /> <span class="">Temperatura Ambiente</span></button>
        <div class="panel centrarGrafico">
            <div class="col-sm-12 col-md-6 centrarGrafico">
                <canvas id="myChart1"></canvas>
            </div>
        </div>
    </div>
    <div class="col-md-6">
        <button class="accordion">
            <img src="../assets/icos/dom.png" height="50" class="colorTituloLuzAmb marginRight" alt="Icono Luz Ambiental" /> <span class="">Luz Ambiental</span>
        </button>
        <div class="panel centrarGrafico">
            <div class="col-sm-12 col-md-6 centrarGrafico">
                <canvas id="myChart2"></canvas>
            </div>
        </div>
    </div>
    <div class="col-md-6">
        <button class="accordion">
            <img src="../assets/icos/humedad.png" height="50" class="colorTituloHumAmb marginRight" alt="Icono Humedad Ambiente" /><span class="">Humedad Ambiente</span> 
        </button>
        <div class="panel centrarGrafico">
            <div class="col-sm-12 col-md-6 centrarGrafico">
                <canvas id="myChart4"></canvas>
            </div>
        </div>
    </div>
    <div class="col-md-6">
        <button class="accordion">
            <img src="../assets/icos/humedadTierra.png" height="50" class="colorTituloHumTie marginRight" alt="Icono Humedad Tierra" /> <span class="">Humedad Tierra</span>
        </button>
        <div class="panel centrarGrafico">
            <div class="col-sm-12 col-md-6 centrarGrafico">
                <canvas id="myChart3"></canvas>
            </div>
        </div>
    </div>
</div><!-- FIN DE ROW -->
           
<br/>
<div v-if="!sizeScreenMovil">
    <GraficosFlex/>
</div>
<div else>

</div>
        
<br/>
</template>
    
<script>
import { ref, onMounted, computed } from 'vue';
import axios from 'axios';
import Chart from 'chart.js/auto';
import GraficosFlex from '../components/CardsFlex.vue'
export default {

    name: 'Graficos-1',
    components: {GraficosFlex},
       setup() {
      
        let registros = ref([]);
        let estado = ref(1);
        let medicion = ref([]);
        let ultimo = ref([]);
        let cara1 = "https://clarys.duckdns.org/faces/1.png";
        let cara2 = "https://clarys.duckdns.org/faces/cara2.gif";
        let cara3 = "https://clarys.duckdns.org/faces/3.png";
        let cara4 = "https://clarys.duckdns.org/faces/4.png";
        let cara5 = "https://clarys.duckdns.org/faces/cara5.gif";

        let este = ref();
        let id = ref([]);
        let tempAmb = ref([]);
        let copyOfDynos = [];
        let luz = [];
        let humTierra = [];
        let humAmbiente = [];
        let horas = []
        let acc = document.getElementsByClassName("accordion");
        let sizeScreenMovil = false;
        let sizeScreenDesktop = false;
        
        if (screen.width < 600) {
                sizeScreenMovil = true;
                console.log("Menos de 600");
                console.log(screen.width)
            } 
            if (screen.width > 600){
                sizeScreenMovil = false;
                console.log("Más de 600");
                console.log(screen.width)
            }

        onMounted(() => {
            
            // if(window.innerHeight > window.innerWidth) {
            //     alert("Vertical"); 
            // } else {     
            //     alert("Horizontal"); 
            // }
        
        

        for (let i = 0; i < acc.length; i++) {
            acc[i].onclick = function(){
                this.classList.toggle("active");
                this.nextElementSibling.classList.toggle("show");
            }
        }
            fetchRegistros();
            fetchEstados();
            pintaGraficaTempAmb();
            pintaGraficaLuz();
            pintaGraficaHumTer();
            pintaGraficaHumAmb();
           
            document.body.style.zoom = "99%";
           
        })




        const face = computed(() => {
            
            return 0;
        })

        const fetchEstados = () => {
            axios.get('https://clarys.duckdns.org:3000/api/estado')
                .then(response => {
                    estado.value = response.data;
                    este.value = estado.value[0].estado;
                })
                .catch(error => {
                    console.error(error);
                });
        };

        const fetchRegistros = () => {
            axios.get('https://clarys.duckdns.org:3000/api/dades')
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

            const ctx = document.getElementById("myChart1");
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

            const ctx = document.getElementById("myChart2");
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

            const ctx = document.getElementById("myChart3");
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

            const ctx = document.getElementById("myChart4");
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




        return { sizeScreenDesktop, sizeScreenMovil, acc, estado, registros, medicion, ultimo, cara1, cara2, cara3, cara4, cara5, face, este, id, tempAmb, copyOfDynos, luz, humTierra };
    }

}
</script>
    
<style scoped>
.container {
    margin-top: 60px;
}
.polaroid {
  height: 200px;
  background-color: white;
  padding: 10px 10px 50px 10px;
  border: 1px solid #bfbfbf;
  box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
}
.centrarGrafico{
  display: flex;
  justify-content: center;
  align-items: center;
  width: 99%;
}
.centrarTituloBoton{
    margin-left: 30px;
}

button.accordion {
    background-color: #eee;
    color: #444;
    cursor: pointer;
    padding: 18px;
    width: 100%;
    border: none;
    text-align: left;
    outline: none;
    font-size: 15px;
    transition: 0.4s;
    border-radius: 15px;
    margin-top: 15px
}

button.accordion.active, button.accordion:hover {
    background-color: #ddd;
    
}

button.accordion:after {
    content: '\02795';
    font-size: 13px;
    color: #777;
    float: right;
    margin-left: 5px;
}

button.accordion.active:after {
    content: "\2796";
}

div.panel {
    padding: 0 18px;
    background-color: white;
    max-height: 0;
    overflow: hidden;
    transition: 0.6s ease-in-out;
    opacity: 0;
}

div.panel.show {
    opacity: 1;
    max-height: 900px;
}
.marginRight{
    margin-right: 60px;
}
.colorTituloTemAmb{
    background-color: red;
    border-radius: 10px;
    padding: 5px;
}
.colorTituloLuzAmb{
    background-color: orange;
    border-radius: 10px;
    padding: 5px;
}
.colorTituloHumAmb{
    background-color: rgb(7, 153, 197);
    border-radius: 10px;
    padding: 5px;
}
.colorTituloHumTie{
    background-color: green;
    border-radius: 10px;
    padding: 5px;
}
</style>