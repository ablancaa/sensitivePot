<template>
<nav class="navbar navbar-dark bg-dark fixed-top">
  <div class="container-fluid">
   
    <router-link to="/" class="nav-link active" aria-current="page"><img src="../assets/icos/Planta.png" height="40"/> <div class="margen"><a class="navbar-brand" href="#">Sensitive Pot</a></div></router-link>
  
    <button class="navbar-toggler" type="button" data-bs-toggle="offcanvas" data-bs-target="#offcanvasDarkNavbar" aria-controls="offcanvasDarkNavbar" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="offcanvas offcanvas-end text-bg-dark" tabindex="-1" id="offcanvasDarkNavbar" aria-labelledby="offcanvasDarkNavbarLabel">
      <div class="offcanvas-header">
        <h5 class="offcanvas-title" id="offcanvasDarkNavbarLabel">Sensitive Pot Menú</h5>
        <button type="button" class="btn-close btn-close-white" data-bs-dismiss="offcanvas" aria-label="Close"></button>
      </div>
      
      <div class="offcanvas-body">
        <ul class="navbar-nav justify-content-end flex-grow-1 pe-3">
          <li class="nav-item">
            <router-link to="/" class="nav-link active" aria-current="page" href="#"> <a class="nav-link active" aria-current="page" href="#">Home</a></router-link>
            </li>
          <li class="nav-item">
            <router-link to="/Graficos" class="nav-link active" aria-current="page">Gráficos</router-link>
          </li>
          <li class="nav-item">
            <router-link to="/Registros" class="nav-link active" aria-current="page">Tabla de Registros</router-link>
          </li>
          <li class="nav-item">
            <router-link to="/Login" class="nav-link active" aria-current="page">Login</router-link>
          </li>
          <li class="nav-item">
            <router-link to="/Register" class="nav-link active" aria-current="page">Registro de usuario</router-link>
          </li>
          <!-- <li class="nav-item">
            <router-link to="/Database" class="nav-link active" aria-current="page">Database</router-link>
          </li> -->
          <li class="nav-item">
            <router-link to="/Sensores" class="nav-link active" aria-current="page">Sensores Utilizados</router-link>
          </li>
          
          <li class="nav-item">
            <router-link to="/Galeria" class="nav-link active" aria-current="page">Galería Fotografías</router-link>
          </li>
          
          <li class="nav-item">
            <a href="https://eljardinencasa.com/diccionario-de-jardineria/glosario/" class="nav-link active" aria-current="page">Diccionario de Jardinería</a>
          </li>
          
          <!-- <li class="nav-item dropdown">
            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
              Mediciones
            </a>
            <ul class="dropdown-menu dropdown-menu-dark">
              <li><a class="dropdown-item" href="#">Action</a></li>
              <li><a class="dropdown-item" href="#">Another action</a></li>
              <li>
                <hr class="dropdown-divider">
              </li>
              <li><a class="dropdown-item" href="#">Something else here</a></li>
            </ul>
          </li> -->
        </ul>
        
        <!-- <form class="d-flex mt-3" role="search">
          <input class="form-control me-2" type="search" placeholder="Search" aria-label="Search">
          <button class="btn btn-success" type="submit">Search</button>
        </form> -->
        <div class="logo">
          <img src="../assets/icos/Planta.png" height="120"/>
        </div>
      </div>
      
    </div>
  </div>
</nav>
</template>

<script>
import {getAuth} from 'firebase/auth';
export default {

    setup () {
     
const auth = getAuth();
const user = auth.currentUser
localStorage.setItem('user', user);
let usuario = localStorage.user;
      //  const auth = getAuth();
       // const usuarioLogado = auth.currentUser;

        return { user, usuario}
    }
}
</script>

<style scoped>
.navbar{
  width: 100%;
}
.logo{
  margin-top: 20px;
}
.margen {
  float: right;
  margin-top: 16px;
  margin-left: 8px;
}
</style>