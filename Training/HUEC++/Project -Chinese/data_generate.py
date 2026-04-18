import random
import pandas as pd

# 姓和名的备选字符
surnames = ['赵', '钱', '孙', '李', '周', '吴', '郑', '王', '冯', '陈', '褚', '卫', '蒋', '沈', '韩', '杨', '朱', '秦', '尤', '许',
            '何', '吕', '施', '张', '孔', '曹', '严', '华', '金', '魏', '陶', '姜', '谢', '邹', '喻', '柏', '水', '窦', '章', '云',
            '苏', '潘', '葛', '奚', '范', '彭', '郎', '鲁', '韦', '昌', '马', '苗', '凤', '花', '方', '俞', '任', '袁', '柳', '酆',
            '鲍', '史', '唐', '费', '廉', '岑', '薛', '雷', '贺', '倪', '汤', '滕', '殷', '罗', '毕', '郝', '邬', '安', '常', '乐',
            '于', '时', '傅', '皮', '卞', '齐', '康', '伍', '余', '元', '卜', '顾', '孟', '平', '黄', '和', '穆', '萧', '尹']
given_names = ['一', '二', '三', '四', '五', '六', '七', '八', '九', '十', '天', '文', '中', '小', '大', '明', '华', '军', '伟', '芳',
               '娜', '敏', '静', '丽', '强', '磊', '洋', '艳', '勇', '娟', '杰', '涛', '霞', '平', '刚', '桂英']

# 部门与对应人员类型
departments = ['销售部', '经理部', '技术部', '销售经理部']
personnel_types = {
    '销售部': '销售人员',
    '经理部': '经理',
    '技术部': '技术人员',
    '销售经理部': '销售经理'
}

# 数据生成
data = []
for i in range(1, 101):
    surname = random.choice(surnames)
    given_name = ''.join(random.choices(given_names, k=random.choice([1, 2])))
    name = surname + given_name
    age = random.randint(18, 65)
    gender = random.choice(['M', 'F'])
    department = random.choice(departments)
    personnel_type = personnel_types[department]

    # 薪水逻辑：职位越高，薪水越高
    if '经理' in personnel_type:
        salary = random.randint(6000, 10000)
    elif '技术' in personnel_type:
        salary = random.randint(5000, 9000)
    else:
        salary = random.randint(3000, 8000)

    data.append([i, name, age, gender, department, personnel_type, salary])

# 创建 DataFrame
df = pd.DataFrame(data, columns=['编号', '姓名', '年龄', '性别', '部门', '人员类型', '薪水'])

# 保存为 ANSI (GBK) 编码的文本文件
df.to_csv('employees.txt', sep=' ', index=False, header=False, encoding='gbk')
