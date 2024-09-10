<template>
  <div class="container">
    <h1>Registros</h1>
    <div class="row align-items-center">
    <div class="col" v-for="estado in estados" :key="estado.id">
      <div class="polaroid" style="width: 10rem;" v-if="estado.estado == 1">
          <img :src="cara1" class="card-img-top" alt="...">
        <div class="card-body">
          <!-- <h5 class="card-title">UNO</h5>
          <p class="card-text"></p> -->
        </div>
        
      </div>
      <div class="polaroid" style="width: 10rem;" v-if="estado.estado == 2">
          <img :src="cara2" class="card-img-top" alt="...">
        <div class="card-body">
          <!-- <h5 class="card-title">DOS</h5>
          <p class="card-text"></p> -->
        </div>
        
      </div>
      <div class="polaroid" style="width: 10rem;" v-if="estado.estado == 3">
          <img :src="cara3" class="card-img-top" alt="...">
        <div class="card-body">
          <!-- <h5 class="card-title">TRES</h5>
          <p class="card-text"></p> -->
        </div>
        
      </div>
      <div class="polaroid" style="width: 10rem;" v-if="estado.estado == 4">
          <img :src="cara4" class="card-img-top" alt="...">
        <div class="card-body">
          <!-- <h5 class="card-title">CUATRO</h5>
          <p class="card-text"></p> -->
        </div>
        
      </div>
      <div class="polaroid" style="width: 10rem;" v-if="estado.estado == 5">
          <img :src="cara5" class="card-img-top" alt="...">
        <div class="card-body">
          <!-- <h5 class="card-title">CINCO</h5>
          <p class="card-text"></p> -->
        </div>
        
      </div>
      <div class="polaroid" style="width: 10rem;" v-if="estado.estado == 6">
          <img :src="cara6" class="card-img-top" alt="...">
        <div class="card-body">
          <!-- <h5 class="card-title">SEIS</h5>
          <p class="card-text"></p> -->
        </div>
        
      </div>
    </div>
    <!-- <div class="col">
      two of three columns
    </div>
    <div class="col">
      One of three columns
    </div> -->
  </div>
    
  
    <!-- <div class="card">
      <img :src="cara1" class="" height="50" width="50" alt="cara1" v-if="estado.estado == 1"/>
      <img :src="cara2" class="" height="50" width="50" alt="cara2" v-if="estado.estado == 2"/>
      <img :src="cara3" class="" height="50" width="50" alt="cara3" v-if="estado.estado == 3"/>
      <img :src="cara4" class="" height="50" width="50" alt="cara4" v-if="estado.estado == 4"/>
      <img :src="cara5" class="" height="50" width="50" alt="cara5" v-if="estado.estado == 5"/>
      <img :src="cara6" class="" height="50" width="50" alt="cara6" v-if="estado.estado == 6"/>
    </div> -->
      

    <br/>
    <br/>
  </div>
    

  
   <div class="container">
    <div class="row">
      <div class="col p-2">
        <table>
        <tr>
          <td><strong></strong></td>
          <td><img src="../assets/icos/celsius.png" height="50" class="icoBotton colorTituloTemAmb" alt="Icono Humedad Tierra" /></td>
          <td><img src="../assets/icos/dom.png" height="50" class="icoBotton colorTituloLuzAmb" alt="Icono Sol" /></td>
          <td><img src="../assets/icos/humedad.png" height="50" class="icoBotton colorTituloHumAmb" alt="Icono Humedad" /></td>
          <td><img src="../assets/icos/humedadTierra.png" height="50" class="icoBotton colorTituloHumTie" alt="Icono Humedad Tierra" /></td>
          <!-- <td><img :src="cara1" height="45" class="borde" alt="Icono Humedad Tierra" /></td> -->
        </tr>
        <tr>
          <td><strong>Hora</strong></td>
          <td><strong>Temperatura <br/>Ambiente</strong></td>
          <td><strong>Luz <br/>Ambiente</strong></td>
          <td><strong>Humedad<br/>Ambiente</strong></td>
          <td><strong>Humedad<br/> Tierra</strong></td>
          <!-- <td><strong>Estado</strong></td> -->
        </tr>
        <tr v-for="registro in registros" :key="registro.id">
            <td>{{registro.hora }}</td>
            <td class="textoGrandeTem">{{registro.tempAmb }}</td>
            <td class="textoGrandeLuz">{{registro.luzAmb }}</td>
            <td class="textoGrandeHum">{{registro.humAmb }}</td>
            <td class="textoGrandeHumTie">{{registro.humTer }}</td>
            <!-- <td v-if="registro.estado == 1"><img :src="cara1" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 2"><img :src="cara2" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 3"><img :src="cara3" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 4"><img :src="cara4" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 5"><img :src="cara5" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 6"><img :src="cara6" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td> -->
        </tr>
        
      </table>
      </div>
      <div class="col p-2">
          <h2>
            Estados
          </h2>
        <table>
          
        <tr>
          <!-- <td><strong></strong></td>
          <td><img src="../assets/icos/celsius.png" height="50" class="icoBotton colorTituloTemAmb" alt="Icono Humedad Tierra" /></td>
          <td><img src="../assets/icos/dom.png" height="50" class="icoBotton colorTituloLuzAmb" alt="Icono Sol" /></td>
          <td><img src="../assets/icos/humedad.png" height="50" class="icoBotton colorTituloHumAmb" alt="Icono Humedad" /></td>
          <td><img src="../assets/icos/humedadTierra.png" height="50" class="icoBotton colorTituloHumTie" alt="Icono Humedad Tierra" /></td> -->
          <!-- <td><img :src="cara1" height="45" class="borde" alt="Icono Humedad Tierra" /></td> -->
        </tr>
        <tr>
          <td><strong>Hora</strong></td>

          <td><strong>Estado</strong></td>
        </tr>
        <tr v-for="registro in registros" :key="registro.id">
            <td>{{registro.hora }}</td>
            <td v-if="registro.estado == 1"><img :src="cara1" height="35" class="" alt="Icono " /><!--<br/>{{registro.estado }}--></td> 
            <td v-if="registro.estado == 2"><img :src="cara2" height="35" class="" alt="Icono " /><!--<br/>{{registro.estado }}--></td>
            <td v-if="registro.estado == 3"><img :src="cara3" height="35" class="" alt="Icono " /><!--<br/>{{registro.estado }}--></td>
            <td v-if="registro.estado == 4"><img :src="cara4" height="35" class="" alt="Icono " /><!--<br/>{{registro.estado }}--></td>
            <td v-if="registro.estado == 5"><img :src="cara5" height="35" class="" alt="Icono " /><!--<br/>{{registro.estado }}--></td>
            <td v-if="registro.estado == 6"><img :src="cara6" height="35" class="" alt="Icono " /><!--<br/>{{registro.estado }}--></td>
        </tr>
        
      </table>
      </div>
   
    </div>
   </div>
<!-- Tabla final -->
<div class="accordion accordion-flush" id="accordionFlushExample">
  <div class="accordion-item">
    <h2 class="accordion-header" id="flush-headingOne">
      <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#flush-collapseOne" aria-expanded="false" aria-controls="flush-collapseOne">
        Registros de sensores
      </button>
    </h2>
    <div id="flush-collapseOne" class="accordion-collapse collapse" aria-labelledby="flush-headingOne" data-bs-parent="#accordionFlushExample">
      <div class="accordion-body">
        <table>
        <tr>
          <td><strong></strong></td>
          <td><img src="../assets/icos/celsius.png" height="50" class="icoBotton colorTituloTemAmb" alt="Icono Humedad Tierra" /></td>
          <td><img src="../assets/icos/dom.png" height="50" class="icoBotton colorTituloLuzAmb" alt="Icono Sol" /></td>
          <td><img src="../assets/icos/humedad.png" height="50" class="icoBotton colorTituloHumAmb" alt="Icono Humedad" /></td>
          <td><img src="../assets/icos/humedadTierra.png" height="50" class="icoBotton colorTituloHumTie" alt="Icono Humedad Tierra" /></td>
          <!-- <td><img :src="cara1" height="45" class="borde" alt="Icono Humedad Tierra" /></td> -->
        </tr>
        <tr>
          <td><strong>Hora</strong></td>
          <td><strong>Temperatura <br/>Ambiente</strong></td>
          <td><strong>Luz <br/>Ambiente</strong></td>
          <td><strong>Humedad<br/>Ambiente</strong></td>
          <td><strong>Humedad<br/> Tierra</strong></td>
          <!-- <td><strong>Estado</strong></td> -->
        </tr>
        <tr v-for="registro in registros" :key="registro.id">
            <td>{{registro.hora }}</td>
            <td class="textoGrandeTem">{{registro.tempAmb }}</td>
            <td class="textoGrandeLuz">{{registro.luzAmb }}</td>
            <td class="textoGrandeHum">{{registro.humAmb }}</td>
            <td class="textoGrandeHumTie">{{registro.humTer }}</td>
            <!-- <td v-if="registro.estado == 1"><img :src="cara1" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 2"><img :src="cara2" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 3"><img :src="cara3" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 4"><img :src="cara4" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 5"><img :src="cara5" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td>
            <td v-if="registro.estado == 6"><img :src="cara6" height="50" class="" alt="Icono " /><br/>{{registro.estado }}</td> -->
        </tr>
        
      </table>
      </div>
    </div>
  </div>
  </div>
   <div class="container">
      
    <tarjetitas/>
    </div>            
   
      
</template>

<script>
import axios from 'axios';


export default {
  name: 'Registro-1',
  data() {
    return {
      registros: [],
      estados: [],
      cara1: "http://clarys.duckdns.org/faces/cara1.png",
      cara2: "http://clarys.duckdns.org/faces/cara2.gif",
      cara3: "http://clarys.duckdns.org/faces/3.png",
      cara4: "http://clarys.duckdns.org/faces/4.png",
      cara5: "http://clarys.duckdns.org/faces/cara5.gif",
      cara6: "http://clarys.duckdns.org/faces/6.png",
    };
  },
  mounted() {
    this.fetchRegistros();
    this.fetchEstados();
  },
  methods: {
    // Método para obtener registros
    async fetchRegistros() {
      try {
        const response = await axios.get('http://clarys.duckdns.org:3001/api/dades');
        this.registros = response.data.reverse();  // Invertimos el array al recibirlo
      } catch (error) {
        console.error('Error al obtener los registros:', error);
      }
    },
    // Método para obtener estados
    async fetchEstados() {
      try {
        const response = await axios.get('http://clarys.duckdns.org:3001/api/estado');
        this.estados = response.data;
        // Actualiza `cara1` si se encuentra el primer estado
        // if (this.estados.length > 0) {
        //   this.cara1 = this.estados[0].estado;
        // }
      } catch (error) {
        console.error('Error al obtener los estados:', error);
      }
    },
    // Método para actualizar datos y refrescar la página
    actualizar() {
      localStorage.setItem('cara1', this.cara1); // Guardar la imagen en localStorage
      this.$router.go(0);  // Refrescar la página
    }
  }
};
</script>
<style>

  table {
    width: 100%;
    border: 1px solid;
  }

  .polaroid {
    height: 100px;
    background-color: white;
    padding: 10px 10px 50px 10px;
    border: 1px solid #bfbfbf;
    box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
    margin-top: 30px;
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

.flex-container {
  display: flex;
  justify-content: center;
}
.alLado {
  float: left;
}

.borde {
 border-radius: 10px;
}
  </style>