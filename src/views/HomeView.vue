<template>
  <div id="todo">
    <div class="contenido">
      <div class="row">
        <div class="col-md-12">
          <h1>{{}}</h1>
        </div>
      </div>
      <div class="row">
        <div class="col-md-6" v-if="este == 1">
          <img :src="cara1" height="" class="polaroid" alt="Cara de interfaz" />
        </div>
        <div class="col-md-6" v-if="este == 2">
          <img :src="cara2" height="" class="polaroid" alt="Cara de interfaz" />
        </div>
        <div class="col-md-6" v-if="este == 3">
          <img :src="cara3" height="" class="polaroid" alt="Cara de interfaz" />
        </div>
        <div class="col-md-6" v-if="este == 4">
          <img :src="cara4" height="" class="polaroid" alt="Cara de interfaz" />
        </div>
        <div class="col-md-6" v-if="este == 5">
          <img :src="cara5" height="" class="polaroid" alt="Cara de interfaz" />
        </div>
        <div class="col-md-6" v-if="este == 6">
          <img :src="cara6" height="" class="polaroid" alt="Cara de interfaz" />
        </div>
        <div class="col-md-6" v-if="este == 7">
          <img :src="cara7" height="" class="polaroid" alt="Cara de interfaz" />
        </div>
        <div class="col-md-6">
          <h4></h4>

          <div class="marcoReloj">
            <Reloj />
          </div>
        </div>
      </div>
    </div>
    <br />
    <div class="container">
      <div>

      </div>
      <table>
        <tr>
          <td>ID</td>
          <td>Dia</td>
          <td>Hora</td>
          <td>Temperatura Ambiente</td>
          <td>Humedad Ambiente</td>
          <td>Humedad Tierra</td>
          <td>Luz Ambiente</td>
        </tr>
        <tr v-for="registro in registros" :key="registro.id">
          <td>{{ registro.id }}</td>
          <td>{{ registro.dia }}</td>
          <td>{{ registro.hora }}</td>
          <td>{{ registro.tempAmb }}</td>
          <td>{{ registro.humAmb }}</td>
          <td>{{ registro.humTer }}</td>
          <td>{{ registro.luzAmb }}</td>
        </tr>
      </table>
    </div>
    <br /><br />
  </div>
</template>

<script>
import { ref, onMounted, computed } from "vue";
import CardHumedad from "/src/components/CardHumedad.vue";
import CardHumedadTierra from "/src/components/CardHumedadTierra.vue";
import CardTemperatura from "/src/components/CardTemperatura.vue";
import Reloj from "/src/components/Reloj.vue";

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
    let cara1 = "http://clarys.ddns.net/faces/1.png";
    let cara2 = "http://clarys.ddns.net/faces/2.png";
    let cara3 = "http://clarys.ddns.net/faces/3.png";
    let cara4 = "http://clarys.ddns.net/faces/4.png";
    let cara5 = "http://clarys.ddns.net/faces/5.png";
    let cara6 = "http://clarys.ddns.net/faces/6.png";
    let cara7 = "http://clarys.ddns.net/faces/7.png";
    let este = ref();
    onMounted(() => {
      fetchEstados();
      fetchRegistros();
      setInterval("location.reload()", 20000);
    });

    const face = computed(() => {
   
      return 1;
    });


    const fetchEstados = () => {
      axios
        .get("http://clarys.ddns.net:3000/api/estado")
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
        .get("http://clarys.ddns.net:3000/api/dades")
        .then((response) => {
          registros.value = response.data;
          ultimo.value = registros.value.reverse();
        })
        .catch((error) => {
          console.error(error);
        });
    };

    return {
      sensitivePot, img, Reloj, CardHumedad, CardHumedadTierra, CardTemperatura, estates,
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
      este
    };
  },
};
</script>
<style scoped>
#todo {
  border-radius: 15px;
  background-image: url("../assets/jardin.jpg");
  background-size: 100%;
}

.contenido {
  margin-top: 70px;
}

table {
  border-radius: 15px;
  color: rgb(0, 0, 0);
  border: 3px solid;
}

td {
  border-block: 2px solid;
  font-size: 16px;
}

tr {
  border: 4px solid;
  font-size: 16px;
}

.centerCard {}

.sensores {
  margin-top: 25px;
  margin-bottom: 40px;
}

li {
  text-align: left;
}

.polaroid {
  height: 300px;
  background-color: white;
  padding: 10px 10px 50px 10px;
  border: 1px solid #bfbfbf;
  box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
}

.marcoReloj {
  margin-right: 15px;
  margin-top: 85px;
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
}</style>
