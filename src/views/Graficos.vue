<template>
    <div class="container">
        <h1>Gráficos</h1>
        <div class="row">
            <div class="col-md-12" v-if="este == 1">
                <img :src="cara1" height="200" class="polaroid" />
            </div>
        <div class="row">
            <div class="col-md-12" v-if="este == 2">
                <img :src="cara2" height="200" class="polaroid" />
            </div>
        </div>
            <div class="col-md-12" v-if="este == 3">
                <img :src="cara3" height="200" class="polaroid" />
            </div>
            <div class="col-md-12" v-if="este == 4">
                <img :src="cara4" height="200" class="polaroid" />
            </div>
            <div class="col-md-12" v-if="este == 5">
                <img :src="cara5" height="200" class="polaroid" />
            </div>
            </div>
            </div><!-- fin -->
<br/>
    <div class="ontainer-fluid">
        <div class="row">
            <div class="col-sm-12 col-md-6 centrarGrafico">
                <canvas id="myChart1"></canvas>
            </div>
            
            <div class="col-sm-12 col-md-6 centrarGrafico">
                <canvas id="myChart2"></canvas>
            </div>
        </div>
        
        <div class="row">
            <div class="col-sm-12 col-md-6 centrarGrafico">
                <canvas id="myChart3"></canvas>
            </div>
            <div class="col-sm-12 col-md-6 centrarGrafico">
                <canvas id="myChart4"></canvas></div>
            </div>
        </div>
        
<br/>
</template>
    
<script>
import { ref, onMounted, computed } from 'vue';
import axios from 'axios';
import Chart from 'chart.js/auto';

export default {

    name: 'Graficos-1',
    setup() {

        let registros = ref([]);
        let estado = ref(1);
        let medicion = ref([]);
        let ultimo = ref([]);
        let cara1 = "http://clarys.ddns.net/faces/1.png";
        let cara2 = "http://clarys.ddns.net/faces/2.png";
        let cara3 = "http://clarys.ddns.net/faces/3.png";
        let cara4 = "http://clarys.ddns.net/faces/4.png";
        let cara5 = "http://clarys.ddns.net/faces/5.png";

        let este = ref();
        let id = ref([]);
        let tempAmb = ref([]);
        let copyOfDynos = [];
        let luz = [];
        let humTierra = [];
        let humAmbiente = [];
        let horas = []



        onMounted(() => {
            fetchRegistros();
            fetchEstados();
            pintaGraficaTempAmb();
            pintaGraficaLuz();
            pintaGraficaHumTer();
            pintaGraficaHumAmb();
            setInterval("location.reload()", 120000);
            document.body.style.zoom = "99%";
        })




        const face = computed(() => {

            return 1;
        })

        const fetchEstados = () => {
            axios.get('http://clarys.ddns.net:3000/api/estado')
                .then(response => {
                    estado.value = response.data;
                    este.value = estado.value[0].estado;
                })
                .catch(error => {
                    console.error(error);
                });
        };

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
                        label: 'Luz',
                        data: luz,
                        borderColor: 'orange',
                        borderWidth: 1
                        
                    }],
                    
                },
                options: {
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
                    scales: {
                        y: {
                            beginAtZero: true
                        }
                    }
                }
            });

        }




        return { estado, registros, medicion, ultimo, cara1, cara2, cara3, cara4, cara5, face, este, id, tempAmb, copyOfDynos, luz, humTierra };
    }

}
</script>
    
<style scoped>
.container {
    margin-top: 60px;
}
.polaroid {
  height: 140px;
  width: 180px;
  background-color: white;
  padding: 10px 10px 20px 10px;
  border: 1px solid #bfbfbf;
  box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
}
.centrarGrafico{
display: flex;
  justify-content: center;
  align-items: center;
}
</style>