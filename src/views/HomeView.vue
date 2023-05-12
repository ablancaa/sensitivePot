<template>
  <div class="contenido">
    <div class="row">
      <div class="col-md-12">
        <h1>{{ }}</h1>
      </div>
    </div>
    <div class="row">
      <div class="col-md-6">
        <h4></h4> <img src="../assets/maceta.jpg" height="" class="polaroid" />
      </div>
      <div class="col-md-6">
        <h4></h4>
        <div class="marcoReloj">
          <Reloj />
        </div>
        <div class="card text-center sensores">
          <ul class="nav nav-pills mb-3" id="pills-tab" role="tablist">
            <li class="nav-item" role="presentation">
              <button class="nav-link active" id="pills-home-tab" data-bs-toggle="pill" data-bs-target="#pills-home"
                type="button" role="tab" aria-controls="pills-home" aria-selected="true">Estado</button>
            </li>
            <li class="nav-item" role="presentation">
              <button class="nav-link" id="pills-profile-tab" data-bs-toggle="pill" data-bs-target="#pills-profile"
                type="button" role="tab" aria-controls="pills-profile" aria-selected="false">Temp.&ordf;</button>
            </li>
            <li class="nav-item" role="presentation">
              <button class="nav-link" id="pills-contact-tab" data-bs-toggle="pill" data-bs-target="#pills-contact"
                type="button" role="tab" aria-controls="pills-contact" aria-selected="false">Humd.ambiente</button>
            </li>
            <li class="nav-item" role="presentation">
              <button class="nav-link" id="pills-other-tab" data-bs-toggle="pill" data-bs-target="#pills-other"
                type="button" role="tab" aria-controls="pills-contact" aria-selected="false">Humed. tierra</button>
            </li>
            <!-- <li class="nav-item" role="presentation">
              <button class="nav-link" id="pills-luz-tab" data-bs-toggle="pill" data-bs-target="#pills-luz" type="button" role="tab" aria-controls="pills-contact" aria-selected="false">Luz</button>
            </li> -->
          </ul>
          <div class="tab-content" id="pills-tabContent">
            <div class="tab-pane fade show active" id="pills-home" role="tabpanel" aria-labelledby="pills-home-tab">
              <ul>
                <div class="container">
                  <div class="row">
                    <div class="col-md-6">
                      <p v-for="(item , index) in lista" :key="index"> {{ item.valores.temperatura }}</p>
                      
                    </div>
                    <div class="col-md-6">
                      <p v-for="(item , index) in lista" :key="index"> {{ item.valores.humedad }}</p>
                          
                      </div>
                  </div>
                  
                  <!-- {{ lista }} -->
                </div>
              </ul>
              <br />
            </div>
            <div class="tab-pane fade" id="pills-profile" role="tabpanel" aria-labelledby="pills-profile-tab">
              <CardTemperatura /><br />
            </div>
            <div class="tab-pane fade" id="pills-contact" role="tabpanel" aria-labelledby="pills-contact-tab">
              <CardHumedad /><br />
            </div>
            <div class="tab-pane fade" id="pills-other" role="tabpanel" aria-labelledby="pills-other-tab">
              <CardHumedadTierra /><br />
            </div>
            <!-- <div class="tab-pane fade" id="pills-luz" role="tabpanel" aria-labelledby="pills-luz-tab"><CardLuz/><br/></div> -->
          </div>
        </div>
      </div>
    </div>
    <br /><br />
  </div>
</template>



<script>
import { ref } from 'vue';
import CardHumedad from '/src/components/CardHumedad.vue';
import CardHumedadTierra from '/src/components/CardHumedadTierra.vue';
import CardTemperatura from '/src/components/CardTemperatura.vue';
import Reloj from '/src/components/Reloj.vue'
import { initializeApp } from 'firebase/app'
import { getDatabase, ref as dbRef } from 'firebase/database'
import { useDatabaseList} from 'vuefire'


/*const firebase = initializeApp({ databaseURL: "https://sensitivepot-d0ada-default-rtdb.europe-west1.firebasedatabase.app", })
    const db = getDatabase(firebase)
    const todosRef = dbRef(db, 'test')
    const todos = useDatabaseList(todosRef)*/
//import {firebaseConfig } from '../utils/firebase.js'


  
export default {
  name: 'HomeView',
  components: { Reloj, CardHumedad, CardHumedadTierra, CardTemperatura },
  setup() {
    const firebase = initializeApp({  
      apiKey: "AIzaSyAq47EHEvsvaqfHTczfl5eaObErq857zs8",
      authDomain: "sensitivepot-d0ada.firebaseapp.com",
      projectId: "sensitivepot-d0ada",
      storageBucket: "sensitivepot-d0ada.appspot.com",
      messagingSenderId: "108383124629",
      appId: "1:108383124629:web:57100d4a065dde146bef9c",
      databaseURL: "https://sensitivepot-d0ada-default-rtdb.europe-west1.firebasedatabase.app/",
    })
    
    const db = getDatabase(firebase)
 
    const todosRef = dbRef(db, 'test')
    const todos = useDatabaseList(todosRef)
    const sensitivePot = "Sensitive Pot";
    const img = "http://localhost/src/assets/logo.png";
    let lista = ref([]);
    
    lista = todos.data.value;   
    

    return { sensitivePot, img, Reloj, CardHumedad, CardHumedadTierra, CardTemperatura, lista, todos };
  }

}
</script>
<style scoped>
.contenido {
  margin-top: 70px;
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
  height: 350px;
  background-color: white;
  padding: 10px 10px 50px 10px;
  border: 1px solid #BFBFBF;
  box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
}

.marcoReloj {
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