<template>
    <div class="container">
        <h1>Gráficos</h1>
        <div class="row">
            <div class="col-md-4">
                <img src="" height="200" class="" />
            </div>
            <br />
            <div class="col-md-4">
                <br /><br />
            </div>
            <div class="col-md-12" v-if="este == 1">
                <img :src="cara1" height="200" class="" />
            </div>
            <div class="col-md-12" v-if="este == 2">
                <img :src="cara2" height="200" class="" />
            </div>
            <div class="col-md-12" v-if="este == 3">
                <img :src="cara3" height="200" class="" />
            </div>
            <div class="col-md-12" v-if="este == 4">
                <img :src="cara4" height="200" class="" />
            </div>
            <div class="col-md-12" v-if="este == 5">
                <img :src="cara5" height="200" class="" />
            </div>


        </div>
        <div class="container">
            <div class="col-md-12">
                <br />
                {{ id }}
                <div  height=""><canvas id="myChart" width="1024"></canvas></div>
                <img src="" height="500" class="" />
            </div>
        </div>
    </div>
</template>
    
<script>
import { ref, onMounted, computed } from 'vue';
import axios from 'axios';
import Chart from 'chart.js/auto';
export default {

    name: 'Graficos-1',
    components: {},
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
        let copyOfDynos = []
        let horas =[]



        onMounted(() => {
            fetchRegistros();
            fetchEstados();
            pintaGrafica();
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
                      //  id.value = ultimo.value[i].hora;
                        horas[i] = ultimo.value[i].hora;
                        tempAmb.value = ultimo.value[i].tempAmb;
                        copyOfDynos[i] = tempAmb.value;
        
                       
                        console.log(copyOfDynos);
                    }
                    copyOfDynos = copyOfDynos.concat(tempAmb.value)
                })
                .catch(error => {
                    console.error(error);
                });

        };
        console.log(horas);
        const pintaGrafica = () => {

            const ctx = document.getElementById("myChart");
            new Chart(ctx, {
                type: 'line',
                data: {
                    labels: horas,
                    datasets: [{
                        label: '# Mediciones',
                        data: copyOfDynos,
                        borderWidth: 2
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



        return { estado, registros, medicion, ultimo, cara1, cara2, cara3, cara4, cara5, face, este, id, tempAmb, copyOfDynos };
    }

}
</script>
    
<style scoped>
.container {
    margin-top: 60px;
}
</style>