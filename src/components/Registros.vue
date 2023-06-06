<template>
    <div>
        <br/>
        <br/>
        <br/>
        <div>
            <h1>Registros</h1>
            <div v-for="estado in estados" :key="estado.id">
              <img src="../assets/faces/1.png" v-if="estado.estado == 1"/>
              <img src="../assets/faces/2.png" v-if="estado.estado == 2"/>
              <img src="../assets/faces/3.png" v-if="estado.estado == 3"/>
              <img src="../assets/faces/4.png" v-if="estado.estado == 4"/>
              <img src="../assets/faces/5.png" v-if="estado.estado == 5"/>
              <img src="../assets/faces/6.png" v-if="estado.estado == 6"/>
              </div>
            </div>
      <br/>
      <table>
        <tr>
            <td>ID</td>
            <td>DIA</td>
            <td>Temperatura Ambiente</td>
            <td>Humedad Ambiente</td>
            <td>Humedad Tierra</td>
            <td>Luz Ambiente</td>
        </tr>
        <tr v-for="registro in registros" :key="registro.id">
            <td>{{registro.id }}</td>
            <td>{{registro.dia }}</td>
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
     
      //setTimeout(this.$forceUpdate(), 5000)
    },
    computed(){
     this.estados = this.fetchEstados()
    
     this.actualizar();
    },
    methods: {
      fetchRegistros() {
        axios.get('/dades')
          .then(response => {
            this.registros = response.data;
            this.registros.reverse();
          })
          .catch(error => {
            console.error(error);
          });
      },
      fetchEstados() {
        axios.get('/estado')
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
  </style>