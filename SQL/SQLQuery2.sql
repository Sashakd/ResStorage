/*�������� ������� �2 ������� ����������*/
CREATE TABLE dbStatusStation
(
	Id INT IDENTITY (1,1) NOT NULL,
	���������������  VARCHAR (50),
	�������������	 VARCHAR(25), 
	����������		 VARCHAR(25),
	�����������			INT,
	�����������			INT,
	���������������� VARCHAR (50),
)
GO

--������������� ����������� � ��������� ��������� ����
ALTER TABLE dbStatusStation ADD CONSTRAINT PK_dbStatusStation PRIMARY KEY (Id);
--ALTER TABLE dbStatusStation ADD CONSTRAINT U_dbStatusStation_C1 UNIQUE (���������������);
ALTER TABLE dbStatusStation ALTER COLUMN ��������������� VARCHAR(50) NOT NULL;
ALTER TABLE dbStatusStation ALTER COLUMN ������������� VARCHAR(25) NOT NULL;
ALTER TABLE dbStatusStation ALTER COLUMN ���������� VARCHAR(25) NOT NULL;
ALTER TABLE dbStatusStation ALTER COLUMN ���������������� VARCHAR(50) NOT NULL;
GO

BULK INSERT dbStatusStation
FROM 'C:\Users\���������\Desktop\SQL\1\TStation.txt'
WITH (fieldterminator = '	', rowterminator = '\n');
GO

select top 1200 * from dbStatusStation;
GO

/*
DROP TABLE dbStatusStation
GO
*/
