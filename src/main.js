import { createApp } from 'vue'
import App from './App.vue'
import './registerServiceWorker'
import router from './router'
import 'bootstrap/dist/css/bootstrap.css'
import bootstrap from 'bootstrap/dist/js/bootstrap.bundle.js'
import axios from 'axios';
axios.defaults.baseURL = 'http://localhost:3000/api'


//import { auth } from '@/utils/firebase.js';
import 'firebase/database'
//import "firebase/auth";

createApp(App).use(router, bootstrap, axios).mount('#app')
