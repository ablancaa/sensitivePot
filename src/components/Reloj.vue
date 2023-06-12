<template>
    <div class="contenedor">
        <div class="reloj">
            <div class="horas tuclase">{{ horas }}</div>
            <div class="divisor tuclase">:</div>
            <div class="minutos tuclase">{{ minutos }}</div>
            <div class="divisor tuclase">:</div>
            <div class="segundos tuclase">{{ segundos }}</div>
        </div>
    </div>
</template>

<script>
    export default {
        name: "RelojDigital",
        data(){
            return {
                horas: 0,
                minutos: 0,
                segundos: 0
            }
        },
        mounted(){
            setInterval(() => this.setTiempo(), 1000)
        },
        methods: {
            setTiempo() {
                const date = new Date(); 
                let horas = date.getHours();
                let minutos = date.getMinutes();
                let segundos = date.getSeconds();
                horas = horas <= 9 ? `${horas}`.padStart(2, 0) : horas;
                minutos = minutos <= 9 ? `${minutos}`.padStart(2, 0) : minutos;
                segundos = segundos <= 9 ? `${segundos}`.padStart(2, 0) : segundos;
                this.horas = horas;
                this.minutos = minutos;
                this.segundos = segundos;
            }
        }
    }
</script>

<style scoped>
    .reloj{
        display: inline-flex;
        font-size: 100px;
    }
    .tuclase{
        text-align: left; 
        font-family: Arial;
        font-weight:bold; 
        font-size: 60px; 
        color: #ffffff; 
        text-shadow: -1px 0 #134cd1, 0 1px #1547bb, 1px 0 #414D68, 0 -1px #21469c, -2px 2px 0 #414D68, 2px 2px 0 #58f543, 1px 1px #414D68, 2px 2px #414D68, 3px 3px #414D68, 4px 4px #414D68, 5px 5px #414D68, 6px 6px #414D68, 7px 7px #414D68, 8px 8px #414D68, 9px 9px #414D68;
}
</style>