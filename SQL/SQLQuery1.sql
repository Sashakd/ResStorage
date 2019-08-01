/*�������� ������� �1 ������-���������*/
-- ���� ��� ���������� ����� ������-��-������
CREATE TABLE dbBaseRoverInfo
(
	Id INT IDENTITY (1,1) NOT NULL,
	������ VARCHAR(25),
	��������� VARCHAR(25),
	������ VARCHAR(25),
	������������ datetime,
	��������� VARCHAR(50),
	
	��������� VARCHAR(25),
	����������� FLOAT,
	��������� VARCHAR(50),
	�������������������� datetime,
	����������� INT,
	����������� INT,
	������ INT,
)
GO

--������������� ����������� � ��������� ��������� ����
ALTER TABLE dbBaseRoverInfo ADD CONSTRAINT PK_dbBaseRoverInfo PRIMARY KEY (Id);
ALTER TABLE dbBaseRoverInfo ADD CONSTRAINT U_dbBaseRoverInfo_C1 UNIQUE (������);
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ��������� VARCHAR(25) NOT NULL;
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ������ VARCHAR(25) NOT NULL;
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ������������ datetime NOT NULL;
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ������ VARCHAR(50) NOT NULL;

ALTER TABLE dbBaseRoverInfo ALTER COLUMN ��������� VARCHAR(25) NOT NULL;
ALTER TABLE dbBaseRoverInfo ADD CONSTRAINT CK_dbBaseRoverInfo_C1 CHECK ((����������� >= 0) AND (����������� <= 100)); 
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ��������� VARCHAR(50) NOT NULL;
ALTER TABLE dbBaseRoverInfo ALTER COLUMN �������������������� datetime NOT NULL;
GO

BULK INSERT dbBaseRoverInfo
FROM 'C:\Users\���������\Desktop\SQL\1\TProfile.txt'
WITH (fieldterminator = '	', rowterminator = '\n');
GO

select top 1200 * from dbBaseRoverInfo;
GO

/*
DROP TABLE dbBaseRoverInfo
GO
*/
