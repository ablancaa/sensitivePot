<template>
  <div class="container">
 <NavBar/>
    <router-view/>
    
</div>

  <Footer />


</template>
<script>
import NavBar from './components/NavBar.vue';
import Footer from './components/Footer.vue';
export default({
  components: {
    NavBar, Footer
  }
})
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 70px;
}

</style>
