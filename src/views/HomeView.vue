<template>
  <div id="todo">
  <div class="contenido">
    <div class="row">
      <div class="col-md-12">
        <h1>{{ }}</h1>
      </div>
    </div>
    <div class="row">
      <div class="col-md-6">

        <h4></h4> <img src="../assets/faces/1.png" height="" class="polaroid" />
      </div>
      <div class="col-md-6">
        <h4></h4>
        
        <div class="marcoReloj">
          <Reloj />
        </div>
      
          
        


        </div>
      </div>
    </div>
    <br/>
    <div class="container">
          <table>
        <tr>
            <td>DIA</td>
            <td>Temperatura Ambiente</td>
            <td>Humedad Ambiente</td>
            <td>Humedad Tierra</td>
            <td>Luz Ambiente</td>
        </tr>
        <tr v-for="registro in registros" :key="registro.id">
            <td>{{registro.dia }}</td>
            <td>{{registro.tempAmb }}</td>
            <td>{{registro.humAmb }}</td>
            <td>{{registro.humTer }}</td>
            <td>{{registro.luzAmb }}</td>
        </tr>
      </table>
        </div>
    <br /><br />
  </div>
</template>



<script>
import { ref,onMounted} from 'vue';
import CardHumedad from '/src/components/CardHumedad.vue';
import CardHumedadTierra from '/src/components/CardHumedadTierra.vue';
import CardTemperatura from '/src/components/CardTemperatura.vue';
import Reloj from '/src/components/Reloj.vue'
import { initializeApp } from 'firebase/app'
import { getDatabase, ref as dbRef } from 'firebase/database'
import { useDatabaseList } from 'vuefire'
import axios from 'axios';

/*const firebase = initializeApp({ databaseURL: "https://sensitivepot-d0ada-default-rtdb.europe-west1.firebasedatabase.app", })
    const db = getDatabase(firebase)
    const todosRef = dbRef(db, 'test')
    const todos = useDatabaseList(todosRef)*/
//import {firebaseConfig } from '../utils/firebase.js'



export default {
  name: 'HomeView',
  components: { Reloj },
  setup() {
    const firebase = initializeApp({ databaseURL: "https://sensitivepot-d0ada-default-rtdb.europe-west1.firebasedatabase.app", })
    const db = getDatabase(firebase)

    const todosRef = dbRef(db, 'test')
    const todos = useDatabaseList(todosRef)
    //const todos = useDatabaseObject(todosRef)
    const sensitivePot = "Sensitive Pot";
    const img = "http://localhost/src/assets/logo.png";
    let lista = ref([todos.data.value]);
    let registros = ref([])
    let estates = ref([]);
    onMounted(() => {
     fetchEstados();
     fetchRegistros();
    })
    const fetchEstados = () =>{
        axios.get('/estado')
          .then(response => {
           estates.value = response.data;
          })
          .catch(error => {
            console.error(error);
          });
      };
      const fetchRegistros = () =>{
        axios.get('/dades')
          .then(response => {
           registros.value = response.data;
          })
          .catch(error => {
            console.error(error);
          });
      };

    
  
    return { sensitivePot, img, Reloj, CardHumedad, CardHumedadTierra, CardTemperatura, lista, todos, estates, registros };
  }

}
</script>
<style scoped>
#todo {
  border-radius: 15px;
  background-image: url('../assets/jardin.jpg');
  background-size: 100%;
  
}
.contenido {
  margin-top: 70px;
  
}
table{
  border-radius: 15px;
  color: rgb(0, 0, 0);
  border: 3px solid;
}
td{
  border-block: 2px solid;
  font-size: 16px;
}
tr{
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
  border: 1px solid #BFBFBF;
  box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
}

.marcoReloj {
  margin-right: 15px;
  margin-top: 85px;
  background-color: #2c2c2c;
  border-radius: 20px;
  border: 5px solid #BFBFBF;
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
</style>