<template>
  <div id="todo">
      <h1></h1>
      <div class="row">

        <div class="col-md-12">
          <h1>{{}}</h1>
        </div>
      </div>
      <div class="row">
        <div class="col-md-6" v-if="este == 1">
          <img :src="cara1" height="" class="polaroid" alt="Cara de interfaz" />
          <span class="msjCara">Observer!!</span>
        </div>
        <div class="col-md-6" v-if="este == 2">
          <img :src="cara2" height="" class="polaroid" alt="Cara de interfaz" />
          <span class="msjCara">Happy</span>
        </div>
        <div class="col-md-6" v-if="este == 3">
          <img :src="cara3" height="" class="polaroid" alt="Cara de interfaz" />
          <span class="msjCara">UUuffff!!!!</span>
        </div>
        <div class="col-md-6" v-if="este == 4">
          <img :src="cara4" height="" class="polaroid" alt="Cara de interfaz" />
          <span class="msjCara">Sad</span>
        </div>
        <div class="col-md-6" v-if="este == 5">
          <img :src="cara5" height="" class="polaroid" alt="Cara de interfaz" />
          <span class="msjCara">Sleeping</span>
        </div>
        <div class="col-md-6" v-if="este == 6">
          <img :src="cara6" height="" class="polaroid" alt="Cara de interfaz" />
          <span class="msjCara">I have died</span>
        </div>
        <div class="col-md-6" v-if="este == 7">
          <img :src="cara7" height="" class="polaroid" alt="Cara de interfaz" />
        </div>
        <div class="col-md-5">
          <h4></h4>
          <div class="marcoReloj centrarGrafico">
            <Reloj />
          </div>
          <div class="col-md-5 marcoMensaje" v-if="este == 1">
            <h4 class="espacioTop">Hola, qué tal??</h4>
          </div>
          <div class="col-md-5 marcoMensaje" v-if="este == 2">
            <h4 class="espacioTop">La luz es agradable y estoy bien de agua!!</h4>
          </div>
          <div class="col-md-5 marcoMensaje" v-if="este == 3">
            <h4 class="espacioTop">Creo que me estoy secando!!</h4>
          </div>
          <div class="col-md-5 marcoMensaje" v-if="este == 4">
            <h4 class="espacioTop">Por Favor!! Riégame!!! Riégame!!</h4>
          </div>
          <div class="col-md-5 marcoMensaje" v-if="este == 5">
            <h4 class="espacioTop">No hay mucha luz. Hora de ir a dormir!!</h4>
          </div>
    </div><!-- DIV TODO -->
    


  <div class="container">
    
    <br/><br/>
    <div class="row">
      <div class="col-md-12">
        <table>
          <tr>
            <td><img src="../assets/icos/celsius.png" height="50" class="icoBotton colorTituloTemAmb" alt="Icono Humedad Tierra" /><p><strong>Temperatura Ambiente</strong></p></td>
            <td><img src="../assets/icos/dom.png" height="50" class="icoBotton colorTituloLuzAmb" alt="Icono Sol" /><p><strong>Luz Ambiental</strong></p></td>
            <td><img src="../assets/icos/humedad.png" height="50" class="icoBotton colorTituloHumAmb" alt="Icono Humedad" /><p><strong>Humedad Ambiente</strong></p></td>
            <td><img src="../assets/icos/humedadTierra.png" height="50" class="icoBotton colorTituloHumTie" alt="Icono Humedad Tierra" /><p><strong>Humedad Tierra</strong></p></td>
          </tr>
          <tr>
            <td class="marcador textoGrandeTem">{{ registros[0].tempAmb }}</td>
            <td class="marcador textoGrandeLuz">{{ registros[0].luzAmb }}</td>
            <td class="marcador textoGrandeHum">{{ registros[0].humAmb }}</td>
            <td class="marcador textoGrandeHumTie">{{ registros[0].humTer }}</td>
          </tr>
        </table>
      </div>
    </div>
      
      </div>
      
   </div>
    </div>
    <br/>
 
    <div class="container" v-if="!sizeScreenMovil">
    <div class="col-sm-12 col-md-12 centrarGrafico">
        <canvas id="myChart5"></canvas>
      </div>
  </div>

    <br />

    <button class="accordion"><img src="../assets/icos/grafico-de-linea.png" height="50" class="marginRight" alt="Icono Registros" /> Graficos</button>
<div class="panel">
    
  <div class="container">
      <div class="row">
        <div class="col-sm-12 col-md-6 centrarGrafico">
          <canvas id="myChart1"></canvas>
        </div>
        <div class="col-sm-12 col-md-6 centrarGrafico">
          <canvas id="myChart2"></canvas>
        </div>
        <div class="col-sm-12 col-md-6 centrarGrafico">
          <canvas id="myChart4"></canvas>
        </div>
        <div class="col-sm-12 col-md-6 centrarGrafico">
          <canvas id="myChart3"></canvas>
        </div>
      </div>
    </div>
      
  </div>
    <!-- <div class="container">
      <div class="row">
        <div class="col-sm-12 col-md-6 centrarGrafico"> -->
          <!-- <canvas id="myChart1"></canvas> -->
        <!-- </div> -->
        <!-- <div class="col-sm-12 col-md-6 centrarGrafico"> -->
          <!-- <canvas id="myChart2"></canvas> -->
        <!-- </div>
        <div class="col-sm-12 col-md-6 centrarGrafico"> -->
          <!-- <canvas id="myChart4"></canvas> -->
        <!-- </div>
        <div class="col-sm-12 col-md-6 centrarGrafico"> -->
          <!-- <canvas id="myChart3"></canvas> -->
        <!-- </div>
      </div>
    </div> -->
    <br />
   <button class="accordion"><img src="../assets/icos/editar.png" height="50" class="marginRight" alt="Icono Registros" /> Registro de sensores</button>
<div class="panel centrarGrafico">
    
  <div class="container">
      <div>

      </div>
      <table>
        <tr>
          <td><strong>Hora</strong></td>
          <td><strong>Temperatura <br/>Ambiente</strong></td>
          <td><strong>Luz <br/>Ambiente</strong></td>
          <td><strong>Humedad<br/>Ambiente</strong></td>
          <td><strong>Humedad<br/> Tierra</strong></td>
          
        </tr>
        <tr v-for="registro in registros" :key="registro.id">
          <td>{{ registro.hora }}</td>
          <td class="textoGrandeTem">{{ registro.tempAmb }}</td>
          <td class="textoGrandeLuz">{{ registro.luzAmb }}</td>
          <td class="textoGrandeHum">{{ registro.humAmb }}</td>
          <td class="textoGrandeHumTie">{{ registro.humTer }}</td>  
        </tr>
      </table>
    </div>
      
  </div>
  <br/>


        
        
</template>

<script>
import { ref, onMounted, computed } from "vue";

import Reloj from "/src/components/Reloj.vue";
import Chart from 'chart.js/auto';
import axios from "axios";

export default {
  name: "HomeView",
  components: { Reloj },
  setup() {
    const sensitivePot = "Sensitive Pot";
    const img = "http://localhost/src/assets/logo.png";

    let registros = ref([{}]);
    let estates = ref([]);
    let medicion = ref([]);
    let ultimo = ref([]);
<<<<<<< HEAD
    let cara1 = "https://clarys.duckdns.org/faces/1.png";
    let cara2 = "https://clarys.duckdns.org/faces/cara2.gif";
    let cara3 = "https://clarys.duckdns.org/faces/3.png";
    let cara4 = "https://clarys.duckdns.org/faces/4.png";
    let cara5 = "https://clarys.duckdns.org/faces/cara5.gif";
    let cara6 = "https://clarys.duckdns.org/faces/6.png";
    let cara7 = "https://clarys.duckdns.org/faces/7.png";
=======
    let cara1 = "http://clarys.duckdns.org/faces/1.png";
    let cara2 = "http://clarys.duckdns.org/faces/cara2.gif";
    let cara3 = "http://clarys.duckdns.org/faces/3.png";
    let cara4 = "http://clarys.duckdns.org/faces/4.png";
    let cara5 = "http://clarys.duckdns.org/faces/cara5.gif";
    let cara6 = "http://clarys.duckdns.org/faces/6.png";
    let cara7 = "http://clarys.duckdns.org/faces/7.png";
>>>>>>> 70b9781527fc7a1519daea4d5f1b088648d7ea3c
    let este = ref();
    let id = ref([]);
    let tempAmb = ref([]);
    let copyOfDynos = [];
    let luz = [];
    let humTierra = [];
    let humAmbiente = [];
    let horas = [];
    let sizeScreenMovil = false;
    let acc = document.getElementsByClassName("accordion");

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
      for (let i = 0; i < acc.length; i++) {
            acc[i].onclick = function(){
                this.classList.toggle("active");
                this.nextElementSibling.classList.toggle("show");
            }
        }
      fetchEstados();
      fetchRegistros();
      pintaGraficaTempAmb();
      pintaGraficaLuz();
      pintaGraficaHumTer();
      pintaGraficaHumAmb();
      pintaGraficaTodo();

      setInterval("location.reload()", 120000);
      document.body.style.zoom = "99%";
      
    });

    const face = computed(() => {

      return 1;
    });


    const fetchEstados = () => {
      axios
<<<<<<< HEAD
        .get("https://clarys.duckdns.org:3000/api/estado")
=======
        .get("http://clarys.duckdns.org:3000/api/estado")
>>>>>>> 70b9781527fc7a1519daea4d5f1b088648d7ea3c
        .then((response) => {
          estates.value = response.data;
          este.value = estates.value[0].estado;
          console.log(estates.value[0].estado)
        })
        .catch((error) => {
          console.error(error);
        });
    };

    const fetchRegistros = () => {
      axios
<<<<<<< HEAD
        .get("https://clarys.duckdns.org:3000/api/dades")
=======
        .get("http://clarys.duckdns.org:3000/api/dades")
>>>>>>> 70b9781527fc7a1519daea4d5f1b088648d7ea3c
        .then((response) => {
          registros.value = response.data;
          ultimo.value = registros.value.reverse();
          registros.value.reverse();
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
        .catch((error) => {
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
            label: 'Luz Ambiental',
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
    const pintaGraficaTodo = () => {
     const datos1 = {
      label: "Temperatura Ambiente / ",
      data: copyOfDynos, // La data es un arreglo que debe tener la misma cantidad de valores que la cantidad de etiquetas
      backgroundColor: 'red',// Color de fondo
      borderColor: 'red',// Color del borde
      borderWidth: 1,// Ancho del borde
     };
     const datos2 = {
      label: "Luz Ambiental / ",
      data: luz, // La data es un arreglo que debe tener la misma cantidad de valores que la cantidad de etiquetas
      backgroundColor: 'orange',// Color de fondo
      borderColor: 'orange',// Color del borde
      borderWidth: 1,// Ancho del borde
     };
     const datos3 = {
      label: "Humedad Ambiental / ",
      data: humAmbiente, // La data es un arreglo que debe tener la misma cantidad de valores que la cantidad de etiquetas
      backgroundColor: 'rgba(35, 153, 240)',// Color de fondo
      borderColor: 'rgba(35, 153, 240)',// Color del borde
      borderWidth: 1,// Ancho del borde
     };
     const datos4 = {
      label: "Humedad Tierra ",
      data: humTierra, // La data es un arreglo que debe tener la misma cantidad de valores que la cantidad de etiquetas
      backgroundColor: 'green',// Color de fondo
      borderColor: 'green',// Color del borde
      borderWidth: 1,// Ancho del borde
     };
     
    const ctx = document.getElementById("myChart5");
      new Chart(ctx, {
        type: 'line',
        data: {
            labels: horas,
            datasets: [
              datos1,
              datos2,
              datos3,
              datos4
            ],
            borderWidth: 1
        },
        options: {
          responsive: true,
          scales: {
            y: {
              beginAtZero: true
            }
          }
        }
      });

    }

    return {
      sensitivePot, img, Reloj, estates,
      registros, medicion,
      ultimo,
      cara1,
      cara2,
      cara3,
      cara4,
      cara5,
      cara6,
      cara7,
      face,
      este, tempAmb, copyOfDynos, luz, humTierra, id, sizeScreenMovil
    };
  },
};
</script>
<style scoped>
#todo {
  border-radius: 15px;
  background-image: url("../assets/jardin.jpg");
  background-size: 100%;
  height: auto;
}

.titulo {
  font-size: 20px;
  background: #ff0000;
  width: 20px;
}

tr {
  border: 1px solid;
  font-size: 18px;
}

.sensores {
  margin-top: 25px;
  margin-bottom: 40px;
}

li {
  text-align: left;
}

.polaroid {
  margin-bottom: 15px;
  height: 200px;
  background-color: white;
  padding: 10px 10px 50px 10px;
  border: 1px solid #bfbfbf;
  box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
}

.marcoReloj {

  margin-top: 30px;
  background-color: #2c2c2c;
  border-radius: 20px;
  border: 5px solid #bfbfbf;
  box-shadow: 20px 20px 30px rgba(104, 104, 103, 0.8);
}

.nav-pills button {
  background: rgb(235, 235, 235);
  margin-left: 1px;
  color: black;
}

.nav-pills button.active {
  background: rgb(0, 0, 0);
  margin-left: 1px;
  color: rgb(255, 255, 255);
}

.centrarGrafico {
  display: flex;
  justify-content: center;
  align-items: center;
}

.marcoMensaje {
  width: auto;
  color: white;
  margin-top: 15px;
  background-color: #2c2c2c;
  border-radius: 20px;
  border: 5px solid #bfbfbf;
  box-shadow: 20px 20px 30px rgba(104, 104, 103, 0.8);
  
}

.marcador,td {
  margin-left: 15px;
  font-size: 16px;
  border-radius: 20px;
  box-shadow: 20px 20px 30px rgba(185, 185, 176, 0.8);
  
}
.textoGrandeTem{
  font-size: 25px;
  color: rgb(255, 0, 0);
}
.textoGrandeLuz{
  font-size: 25px;
  color: rgb(228, 149, 2);
}
.textoGrandeHum{
  font-size: 25px;
  color: rgb(48, 148, 241);
}
.textoGrandeHumTie{
  font-size: 25px;
  color: rgb(10, 156, 30);
}
table,td,tr {
  border: 0px;;
  border-style: none;
}
.espacioTop {
  margin-top: 10px;
}
.msjCara{
  position: absolute;
  margin-top: 194px;
  margin-left: -155px;
  font-family: Arial, Helvetica, sans-serif;
}
button.accordion {
    background-color: #eee;
    color: #444;
    cursor: pointer;
    padding: 18px;
    width: 100%;
    border: none;
    border-radius: 15px;
    text-align: left;
    outline: none;
    font-size: 15px;
    transition: 0.4s;
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
    max-height: 2250px;
}
.icoBotton {
  margin-bottom: 10px;
}
.marginRight{
    margin-right: 60px;
}
.colorTituloTemAmb{
    background-color: red;
    border-radius: 10px;
    padding: 5px;
    box-shadow: 10px 1px 5px 1px rgba(255, 167, 167, 0.8);
}
.colorTituloLuzAmb{
    background-color: orange;
    border-radius: 10px;
    padding: 5px;
    box-shadow: 10px 1px 5px 1px rgba(245, 198, 128, 0.8);
}
.colorTituloHumAmb{
    background-color: rgb(7, 153, 197);
    border-radius: 10px;
    padding: 5px;
    box-shadow: 10px 1px 5px 1px rgb(171, 233, 252);
}
.colorTituloHumTie{
    background-color: green;
    border-radius: 10px;
    padding: 5px;
    box-shadow: 10px 1px 5px 1px rgb(180, 250, 186);
}
.grande {
  width: 100%;
  height: 100%;
  position: relative;
}
</style>
