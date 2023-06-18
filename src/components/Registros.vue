<template>
  
    <div>
        <div>
            <h1>Registros</h1>
            <div v-for="estado in estados" :key="estado.id">
              <img :src="cara1" v-if="estado.estado == 1" class="polaroid" height=""/>
              <img :src="cara2" v-if="estado.estado == 2" class="polaroid" height=""/>
              <img :src="cara3" v-if="estado.estado == 3" class="polaroid" height=""/>
              <img :src="cara4" v-if="estado.estado == 4" class="polaroid" height=""/>
              <img :src="cara5" v-if="estado.estado == 5" class="polaroid" height=""/>
              <img :src="cara6" v-if="estado.estado == 6" class="polaroid" height=""/>
              </div>
            </div>
      <br/>
      <!-- <button class="accordion"><img src="../assets/icos/editar.png" height="50" class="colorTituloCard" alt="Icono Registros" /> Registro de sensores</button>
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
          
      </div> -->
      <br/><br/>
      <table>
        <tr>
          <td><strong>Hora</strong></td>
          <td><strong>Temperatura <br/>Ambiente</strong></td>
          <td><strong>Luz <br/>Ambiente</strong></td>
          <td><strong>Humedad<br/>Ambiente</strong></td>
          <td><strong>Humedad<br/> Tierra</strong></td>
        </tr>
        <tr v-for="registro in registros" :key="registro.id">
            <td>{{registro.hora }}</td>
            <td class="textoGrandeTem">{{registro.tempAmb }}</td>
            <td class="textoGrandeHum">{{registro.humAmb }}</td>
            <td class="textoGrandeHumTie">{{registro.humTer }}</td>
            <td class="textoGrandeLuz">{{registro.luzAmb }}</td>
        </tr>
      </table>
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
         cara1: "http://clarys.ddns.net/faces/1.png",
         cara2: "http://clarys.ddns.net/faces/cara2.gif",
         cara3: "http://clarys.ddns.net/faces/3.png",
         cara4: "http://clarys.ddns.net/faces/4.png",
         cara5: "http://clarys.ddns.net/faces/cara5.gif",
        acc: document.getElementsByClassName("accordion"),
      };
    },
    mounted() {
      this.fetchRegistros();
      this.cara1 = this.fetchEstados();
      for (let i = 0; i < this.acc.length; i++) {
            this.acc[i].onclick = function(){
                this.classList.toggle("active");
                this.nextElementSibling.classList.toggle("show");
            }
        }
    },
    computed(){
     this.estados = this.fetchEstados()
     this.actualizar();
    },
    methods: {
      fetchRegistros() {
        axios.get('http://clarys.ddns.net:3000/api/dades')
          .then(response => {
            this.registros = response.data;
            this.registros.reverse();
          })
          .catch(error => {
            console.error(error);
          });
      },
      fetchEstados() {
        axios.get('http://clarys.ddns.net:3000/api/estado')
          .then(response => {
            this.estados = response.data;
          })
          .catch(error => {
            console.error(error);
          });
      },
      actualizar() {
        window.localStorage = this.cara1;
        this.$router.go(0);
        return this.estados = this.fetchEstados;
      }
    }
  };
</script>
<style>
  table{
    width: 100%;
    border: 1px solid;
  }
  .polaroid {
    height: 200px;
    background-color: white;
    padding: 10px 10px 50px 10px;
    border: 1px solid #bfbfbf;
    box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
    margin-top: 30px;
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
  </style>