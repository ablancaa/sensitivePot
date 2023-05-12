import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default {
    namespace: true,

    state: {
        items: [],
    },

    getters:{
        Items(state){
            return state.Items;
        }
    },

    mutations: {
        LlenarItems(state, data){
            state.Items = data;
        }
    },

    actions: {
        cargarDatos: async function({commit}){
            try {
                const setting = {
                    method: 'GET',
                }
                const url = 'http://clarys.ddns.net';
                const data = await fetch(url, setting);
                const json = await data.json();
                commit('LlenarItems', json)
            }
            catch(err){
                console.log(err)
            }
        }
    },


}