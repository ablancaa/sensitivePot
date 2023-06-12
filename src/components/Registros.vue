<template>
    <div>
        <br/>
        <br/>
        <br/>
        <div>
            <h1>Registros</h1>
            <div v-for="estado in estados" :key="estado.id">
              <img src="../assets/faces/1.png" v-if="estado.estado == 1" class="polaroid" height="200"/>
              <img src="../assets/faces/2.png" v-if="estado.estado == 2" class="polaroid" height="200"/>
              <img src="../assets/faces/3.png" v-if="estado.estado == 3" class="polaroid" height="200"/>
              <img src="../assets/faces/4.png" v-if="estado.estado == 4" class="polaroid" height="200"/>
              <img src="../assets/faces/5.png" v-if="estado.estado == 5" class="polaroid" height="200"/>
              <img src="../assets/faces/6.png" v-if="estado.estado == 6" class="polaroid" height="200"/>
              </div>
            </div>
      <br/>
      <table>
        <tr>
            <td>Hora</td>
            <td>Temperatura Ambiente</td>
            <td>Humedad Ambiente</td>
            <td>Humedad Tierra</td>
            <td>Luz Ambiente</td>
        </tr>
        <tr v-for="registro in registros" :key="registro.id">
            <td>{{registro.hora }}</td>
            <td>{{registro.tempAmb }}</td>
            <td>{{registro.humAmb }}</td>
            <td>{{registro.humTer }}</td>
            <td>{{registro.luzAmb }}</td>
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
        cara1: 1,
      };
    },
    mounted() {
      this.fetchRegistros();
      this.cara1 = this.fetchEstados();
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
  height: 140px;
  background-color: white;
  padding: 10px 10px 20px 10px;
  border: 1px solid #bfbfbf;
  box-shadow: 10px 10px 20px rgba(0, 0, 0, 0.8);
  margin-top: 30px;
}
  </style>