var app = new Vue({
    el:'#container',
    data: {
        bathroomId:123456,//编号
        status:[0,0,0,0,0]
    },
    computed: {
        now:function(){
            //计算当前洗澡人数
            var n=0;
            for(var i=0; i<this.status.length;i++){
                n+=parseInt(this.status[i]);
            }
            return n;
        },
        max:function(){
            //获得容量
            return this.status.length;
        }
    },
    methods:{
        getIn:function(event){//todo
        },
        changeId:function(){//测试用改变id
            Vue.set(this,'bathroomId',document.getElementById("bathroomId").value);
        },
    },
    watch:{
        status:function(){//todo 待完善的xhr
            axios
            .post("http://127.0.0.1/updateBathroomStatus",{
                "bathroomId":this.bathroomId,
                "status":this.status
            })
            .then()
        },
    }
})