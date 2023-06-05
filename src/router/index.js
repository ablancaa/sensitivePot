import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../views/HomeView.vue'
import Register from '../views/Register.vue'
import Sensores from '../views/Sensores.vue'
import Database from '../components/prueba.vue'
import Registros from '../components/Registros.vue'
import Login from '../views/Login.vue'
Sensores-1
const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView
  },
  {
    path: '/Register',
    name: 'Register',
    component: Register
  },
  {
    path: '/Sensores',
    name: 'Sensores-1',
    component: Sensores
  },
  {
    path: '/Database',
    name: 'Database',
    component: Database
  },
  {
    path: '/Login',
    name: 'Login',
    component: Login
  },
  {
    path: '/Registros',
    name: 'Registros',
    component: Registros
  },
  {
    path: '/about',
    name: 'about',
    // route level code-splitting
    // this generates a separate chunk (about.[hash].js) for this route
    // which is lazy-loaded when the route is visited.
    component: () => import(/* webpackChunkName: "about" */ '../views/AboutView.vue')
  }
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes
})

export default router
